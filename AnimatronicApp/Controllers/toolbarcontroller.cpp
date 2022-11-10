#include "toolbarcontroller.h"

ToolBarController::ToolBarController(QObject *parent)
    : QObject(parent),
      m_bluetoothDeviceDiscoveryAgent(new QBluetoothDeviceDiscoveryAgent(this)),
      m_serialPortOpenButtonText("Conectar"),
      m_isSerialPortOpen(false),
      m_btEnabled(true),
      m_btConnectionCheckBoxEnabled(true),
      m_timer(new QTimer(this))
{
    scanSerialPorts();

    // Timer will check every second for new available ports
    connect(m_timer, &QTimer::timeout, this, &ToolBarController::scanSerialPorts);
    m_timer->start(1000);

    connect(m_bluetoothDeviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &ToolBarController::bluetoothDevicedDiscovered);

    m_bluetoothDeviceDiscoveryAgent->start();
}

const QVariantList &ToolBarController::availablePortsList() const
{
    if(m_btEnabled)
    {
        return m_availableBTDevicesList;
    }
    else
    {
        return m_availablePortsList;
    }
}

void ToolBarController::onOpenSerialPortPressed(int currentIndex)
{
    if(currentIndex < 0)
    {
        return;
    }

    if(!m_isSerialPortOpen)
    {
        if(m_btEnabled)
        {
            emit btDeviceConnectionRequested(m_bluetoothDeviceInfoTable[m_availableBTDevicesList.at(currentIndex).toString()]);
        }
        else
        {
            emit serialPortOpenRequested(m_availablePortsList.at(currentIndex).toString());
        }

        m_btConnectionCheckBoxEnabled = false;
        emit btConnectionCheckBoxEnabledChanged();
    }
    else
    {
        if(m_btEnabled)
        {
            emit btDeviceDisconnectionRequested();
        }
        else
        {
            emit serialPortCloseRequested();
        }

        m_btConnectionCheckBoxEnabled = true;
        emit btConnectionCheckBoxEnabledChanged();
    }
}

void ToolBarController::onBTEnabledPressed(bool checked)
{
    if(m_btEnabled != checked)
    {
        m_btEnabled = checked;

        if(m_btEnabled)
        {
            m_timer->stop();
        }
        else
        {
            m_timer->start(1000);
        }

        emit availablePortsListChanged();
    }
}

void ToolBarController::bluetoothDevicedDiscovered(const QBluetoothDeviceInfo &newDevice)
{
    m_availableBTDevicesList.append(newDevice.name());
    m_bluetoothDeviceInfoTable.insert(newDevice.name(), newDevice);
    emit availablePortsListChanged();
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

bool ToolBarController::btConnectionCheckBoxEnabled() const
{
    return m_btConnectionCheckBoxEnabled;
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

        m_serialPortOpenButtonText = m_isSerialPortOpen ? "Desconectar" : "Conectar";

        emit serialPortOpenButtonTextChanged();
    }
}

const QString &ToolBarController::serialPortOpenButtonText() const
{
    return m_serialPortOpenButtonText;
}
