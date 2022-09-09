#include "animatroniccontrol.h"

#define MOVE_EYES_MESSAGE_ID 0x04
#define MOVE_EYELIDS_MESSAGE_ID 0x05
#define MOVE_EYEBROWS_MESSAGE_ID 0x06
#define MOVE_MOUTH_MESSAGE_ID 0x07

AnimatronicControl::AnimatronicControl(QObject *parent)
    : QObject(parent),
      m_communicationThread(new CommunicationThread(this)),
      m_communicationTimer(new QTimer(this)),
      m_eyesController(new JoystickController(this)),
      m_toolBarController(new ToolBarController(this)),
      m_eyelidsController(new SliderController(this)),
      m_leftEyebrowController(new LeverController(this)),
      m_rightEyebrowController(new LeverController(this)),
      m_mouthController(new SliderController),
      m_eyesControl(new EyesControl(this)),
      m_eyelidsControl(new EyelidsControl(this)),
      m_eyebrowsControl(new EyebrowsControl(this)),
      m_mouthControl(new MouthControl(this))
{
    //TOOLBAR:
    connect(m_toolBarController, &ToolBarController::serialPortOpenRequested,
            m_communicationThread, &CommunicationThread::openSerialPort);

    connect(m_toolBarController, &ToolBarController::serialPortCloseRequested,
            m_communicationThread, &CommunicationThread::closeSerialPort);

    //COMMUNICATION TIMER
    connect(m_communicationTimer, &QTimer::timeout, this, &AnimatronicControl::sendPositions);

    //COMMUNICATION THREAD
    connect(m_communicationThread, &CommunicationThread::serialPortOpened, m_toolBarController, [this](){
        m_toolBarController->setIsSerialPortOpen(true);
        startCommunicationTimer();
    });

    connect(m_communicationThread, &CommunicationThread::serialPortClosed, m_toolBarController, [this](){
        m_toolBarController->setIsSerialPortOpen(false);
        stopCommunicationTimer();
    });

    //EYES:
    connect(m_eyesController, &JoystickController::joystickPositionChanged, this, [this](){

        m_eyesControl->setPositionDegrees(m_eyesController->joystickPosition());
        m_eyelidsControl->setPositionCenterYOffsetDegrees(m_eyesController->joystickPosition().y());
    });

    //EYELIDS:
    connect(m_eyelidsController, &SliderController::sliderPositionChanged, m_eyelidsControl, [this](){

        m_eyelidsControl->setPositionDegrees({m_eyelidsController->sliderPosition(), m_eyelidsController->sliderPosition()});
    });

    //EYEBROWS:
    connect(m_leftEyebrowController, &LeverController::rotationChanged, m_eyebrowsControl, [this](){

        m_eyebrowsControl->setLeftRotationDegrees(m_leftEyebrowController->rotation());
    });

    connect(m_rightEyebrowController, &LeverController::rotationChanged, m_eyebrowsControl, [this](){

        m_eyebrowsControl->setRightRotationDegrees(m_rightEyebrowController->rotation());
    });

    //MOUTH
    connect(m_mouthController, &SliderController::sliderPositionChanged, m_mouthControl, [this](){

        m_mouthControl->setPositionDegrees(m_mouthController->sliderPosition());
    });
}

JoystickController *AnimatronicControl::eyesController() const
{
    return m_eyesController;
}

ToolBarController *AnimatronicControl::toolBarController() const
{
    return m_toolBarController;
}

void AnimatronicControl::sendEyesPosition(QPointF eyesPosition)
{
    QByteArray dataOut;

    dataOut.append(MOVE_EYES_MESSAGE_ID);

    dataOut.append(quint16(eyesPosition.x() * 100) >> 0);
    dataOut.append(quint16(eyesPosition.x() * 100) >> 8);

    dataOut.append(quint16(eyesPosition.y() * 100) >> 0);
    dataOut.append(quint16(eyesPosition.y() * 100) >> 8);

    m_communicationThread->sendData(dataOut);
}

void AnimatronicControl::sendEyelidsPosition(QPair<float, float> eyelidsPosition)
{
    QByteArray dataOut;

    dataOut.append(MOVE_EYELIDS_MESSAGE_ID);

    dataOut.append(quint16(eyelidsPosition.first * 100) >> 0);
    dataOut.append(quint16(eyelidsPosition.first * 100) >> 8);

    dataOut.append(quint16(eyelidsPosition.second * 100) >> 0);
    dataOut.append(quint16(eyelidsPosition.second * 100) >> 8);

    m_communicationThread->sendData(dataOut);
}

void AnimatronicControl::sendEyebrowsRotation(QPair<float, float> eyebrowsPosition)
{
    QByteArray dataOut;

    dataOut.append(MOVE_EYEBROWS_MESSAGE_ID);

    dataOut.append(quint16(eyebrowsPosition.first * 100) >> 0);
    dataOut.append(quint16(eyebrowsPosition.first * 100) >> 8);

    dataOut.append(quint16(eyebrowsPosition.second * 100) >> 0);
    dataOut.append(quint16(eyebrowsPosition.second * 100) >> 8);

    m_communicationThread->sendData(dataOut);
}

void AnimatronicControl::sendMouthPosition(float mouthPosition)
{
    QByteArray dataOut;

    dataOut.append(MOVE_MOUTH_MESSAGE_ID);

    dataOut.append(quint16(mouthPosition * 100) >> 0);
    dataOut.append(quint16(mouthPosition * 100) >> 8);

    m_communicationThread->sendData(dataOut);
}

void AnimatronicControl::sendPositions()
{
    static uint index = 0;

    switch (index)
    {
        case 0:
            sendEyesPosition(m_eyesControl->positionDegrees());
        break;
        case 1:
            sendEyelidsPosition(m_eyelidsControl->positionDegrees());
        break;
        case 2:
            sendEyebrowsRotation(m_eyebrowsControl->positionDegrees());
        break;
        case 3:
            sendMouthPosition(m_mouthControl->positionDegrees());
        break;
    }

    if(index++ > 3)
    {
        index = 0;
    }
}

void AnimatronicControl::startCommunicationTimer()
{
    m_communicationTimer->start(2);
}

void AnimatronicControl::stopCommunicationTimer()
{
    m_communicationTimer->stop();
}

SliderController *AnimatronicControl::mouthController() const
{
    return m_mouthController;
}

SliderController *AnimatronicControl::eyelidsController() const
{
    return m_eyelidsController;
}

LeverController *AnimatronicControl::leftEyebrowController() const
{
    return m_leftEyebrowController;
}

LeverController *AnimatronicControl::rightEyebrowController() const
{
    return m_rightEyebrowController;
}
