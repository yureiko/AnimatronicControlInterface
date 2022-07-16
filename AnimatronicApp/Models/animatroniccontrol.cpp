#include "animatroniccontrol.h"

#define MOVE_EYES_MESSAGE_ID 0x04
#define MOVE_EYELIDS_MESSAGE_ID 0x05

AnimatronicControl::AnimatronicControl(QObject *parent)
    : QObject(parent),
      m_communicationThread(new CommunicationThread(this)),
      m_joystickController(new JoystickController(this)),
      m_toolBarController(new ToolBarController(this)),
      m_sliderController(new SliderController(this)),
      m_leverController(new LeverController(this)),
      m_eyesControl(new EyesControl(this)),
      m_eyelidsControl(new EyelidsControl(this))
{
    connect(m_toolBarController, &ToolBarController::serialPortOpenRequested,
            m_communicationThread, &CommunicationThread::openSerialPort);

    connect(m_toolBarController, &ToolBarController::serialPortCloseRequested,
            m_communicationThread, &CommunicationThread::closeSerialPort);

    connect(m_communicationThread, &CommunicationThread::serialPortOpened, m_toolBarController, [this](){
        m_toolBarController->setIsSerialPortOpen(true);
    });

    connect(m_communicationThread, &CommunicationThread::serialPortClosed, m_toolBarController, [this](){
        m_toolBarController->setIsSerialPortOpen(false);
    });

    connect(m_joystickController, &JoystickController::joystickPositionChanged, this, [this](){

        m_eyesControl->setPositionDegrees(m_joystickController->joystickPosition());
        m_eyelidsControl->setPositionCenterYOffsetDegrees(m_joystickController->joystickPosition().y());
    });

    connect(m_eyesControl, &EyesControl::positionDegreesChanged, this, &AnimatronicControl::sendEyesPosition);

    connect(m_sliderController, &SliderController::sliderPositionChanged, m_eyelidsControl, [this](){

        m_eyelidsControl->setPositionDegrees({m_sliderController->sliderPosition(), m_sliderController->sliderPosition()});
    });

    connect(m_eyelidsControl, &EyelidsControl::positionDegreesChanged, this, &AnimatronicControl::sendEyelidsPosition);
}

JoystickController *AnimatronicControl::joystickController() const
{
    return m_joystickController;
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

SliderController *AnimatronicControl::sliderController() const
{
    return m_sliderController;
}

LeverController *AnimatronicControl::leverController() const
{
    return m_leverController;
}

