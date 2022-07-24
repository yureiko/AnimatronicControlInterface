#include "animatroniccontrol.h"

#define MOVE_EYES_MESSAGE_ID 0x04
#define MOVE_EYELIDS_MESSAGE_ID 0x05
#define MOVE_EYEBROWS_MESSAGE_ID 0x06

AnimatronicControl::AnimatronicControl(QObject *parent)
    : QObject(parent),
      m_communicationThread(new CommunicationThread(this)),
      m_eyesController(new JoystickController(this)),
      m_toolBarController(new ToolBarController(this)),
      m_eyelidsController(new SliderController(this)),
      m_leftEyebrowController(new LeverController(this)),
      m_rightEyebrowController(new LeverController(this)),
      m_eyesControl(new EyesControl(this)),
      m_eyelidsControl(new EyelidsControl(this)),
      m_eyebrowsControl(new EyebrowsControl(this))
{
    //TOOLBAR:
    connect(m_toolBarController, &ToolBarController::serialPortOpenRequested,
            m_communicationThread, &CommunicationThread::openSerialPort);

    connect(m_toolBarController, &ToolBarController::serialPortCloseRequested,
            m_communicationThread, &CommunicationThread::closeSerialPort);

    //COMMUNICATION THREAD
    connect(m_communicationThread, &CommunicationThread::serialPortOpened, m_toolBarController, [this](){
        m_toolBarController->setIsSerialPortOpen(true);
    });

    connect(m_communicationThread, &CommunicationThread::serialPortClosed, m_toolBarController, [this](){
        m_toolBarController->setIsSerialPortOpen(false);
    });

    //EYES:
    connect(m_eyesController, &JoystickController::joystickPositionChanged, this, [this](){

        m_eyesControl->setPositionDegrees(m_eyesController->joystickPosition());
        m_eyelidsControl->setPositionCenterYOffsetDegrees(m_eyesController->joystickPosition().y());
    });

    connect(m_eyesControl, &EyesControl::positionDegreesChanged, this, &AnimatronicControl::sendEyesPosition);

    //EYELIDS:
    connect(m_eyelidsController, &SliderController::sliderPositionChanged, m_eyelidsControl, [this](){

        m_eyelidsControl->setPositionDegrees({m_eyelidsController->sliderPosition(), m_eyelidsController->sliderPosition()});
    });

    connect(m_eyelidsControl, &EyelidsControl::positionDegreesChanged, this, &AnimatronicControl::sendEyelidsPosition);

    //EYEBROWS:
    connect(m_leftEyebrowController, &LeverController::rotationChanged, m_eyebrowsControl, [this](){

        m_eyebrowsControl->setLeftRotationDegrees(m_leftEyebrowController->rotation());
    });

    connect(m_rightEyebrowController, &LeverController::rotationChanged, m_eyebrowsControl, [this](){

        m_eyebrowsControl->setRightRotationDegrees(m_rightEyebrowController->rotation());
    });

    connect(m_eyebrowsControl, &EyebrowsControl::rotationDegreesChanged, this, [this](){
        sendEyebrowsRotation(
                    QPair<float, float>(m_eyebrowsControl->leftRotationDegrees(),
                                        m_eyebrowsControl->rightRotationDegrees()));
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
