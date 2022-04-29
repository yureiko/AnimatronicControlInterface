#include "animatroniccontrol.h"

AnimatronicControl::AnimatronicControl(QObject *parent)
    : QObject(parent),
      m_communicationThread(new CommunicationThread(this)),
      m_joystickController(nullptr),
      m_toolBarController(nullptr)
{

}

JoystickController *AnimatronicControl::joystickController() const
{
    return m_joystickController;
}

void AnimatronicControl::setJoystickController(JoystickController *newJoystickController)
{
    m_joystickController = newJoystickController;
    m_joystickController->setParent(this);
}

ToolBarController *AnimatronicControl::toolBarController() const
{
    return m_toolBarController;
}

void AnimatronicControl::setToolBarController(ToolBarController *newToolBarController)
{
    m_toolBarController = newToolBarController;
    m_toolBarController->setParent(this);
}

void AnimatronicControl::setConnections()
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
}
