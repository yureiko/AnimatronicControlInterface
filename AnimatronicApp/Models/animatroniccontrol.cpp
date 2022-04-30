#include "animatroniccontrol.h"

#define MOVE_EYES_MESSAGE_ID 0x04

AnimatronicControl::AnimatronicControl(QObject *parent)
    : QObject(parent),
      m_communicationThread(new CommunicationThread(this)),
      m_joystickController(new JoystickController(this)),
      m_toolBarController(new ToolBarController(this)),
      m_eyesControl(new EyesControl(this))
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

    connect(m_joystickController, &JoystickController::joystickPositionChanged, m_eyesControl, [this](){

        m_eyesControl->setPositionDegrees(m_joystickController->joystickPosition());
    });

    connect(m_eyesControl, &EyesControl::positionDegreesChanged, this, &AnimatronicControl::sendEyesPosition);
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

