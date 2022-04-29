#include "toolbarcontroller.h"

ToolBarController::ToolBarController(QObject *parent)
    : QObject(parent),
      m_serialPortOpenButtonText("Open"),
      m_isSerialPortOpen(false),
      m_timer(new QTimer(this))
{
    scanSerialPorts();

    // Timer will check every second for new available ports
    connect(m_timer, &QTimer::timeout, this, &ToolBarController::scanSerialPorts);
    m_timer->start(1000);
}

const QVariantList &ToolBarController::availablePortsList() const
{
    return m_availablePortsList;
}

void ToolBarController::onOpenSerialPortPressed(int currentIndex)
{
    if(currentIndex < 0)
    {
        return;
    }

    if(!m_isSerialPortOpen)
    {
        emit serialPortOpenRequested(m_availablePortsList.at(currentIndex).toString());
    }
    else
    {
        emit serialPortCloseRequested();
    }
}

void ToolBarController::scanSerialPorts()
{
    QSerialPortInfo serialPortInfo;
    QList<QSerialPortInfo> serialPortInfoList = serialPortInfo.availablePorts();

    m_availablePortsList.clear();

    foreach(auto serialPort, serialPortInfoList)
    {
        m_availablePortsList.append(QVariant(serialPort.portName()));
    }

    emit availablePortsListChanged();
}

bool ToolBarController::isSerialPortOpen() const
{
    return m_isSerialPortOpen;
}

void ToolBarController::setIsSerialPortOpen(bool newIsSerialPortOpen)
{
    if(m_isSerialPortOpen != newIsSerialPortOpen)
    {
        m_isSerialPortOpen = newIsSerialPortOpen;

        m_serialPortOpenButtonText = m_isSerialPortOpen ? "Close" : "Open";

        emit serialPortOpenButtonTextChanged();
    }
}

const QString &ToolBarController::serialPortOpenButtonText() const
{
    return m_serialPortOpenButtonText;
}
