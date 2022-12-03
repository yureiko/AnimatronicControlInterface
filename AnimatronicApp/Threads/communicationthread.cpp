#include "communicationthread.h"
#include <QBluetoothDeviceInfo>
#include <QDebug>

#define DATA_START_MESSAGE_FLAG 0xAA
#define DATA_END_MESSAGE_FLAG 0x55
#define MAX_OUT_BUFFER 12

CommunicationThread::CommunicationThread(QObject *parent)
    : QThread(parent),
      m_serialPort(new QSerialPort(this)),
      m_btSocket(nullptr),
      m_quit(false)
{
    m_serialPort->setBaudRate(QSerialPort::Baud115200);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::EvenParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
}

void CommunicationThread::run()
{
    m_quit = false;

    if(m_serialPort->isOpen())
    {
        m_serialPort->clear();
    }

    while(!m_quit)
    {
        if(m_serialPort->isOpen())
        {
            if(!m_dataOut.isEmpty() && m_serialPort->isWritable())
            {
                QByteArray dataSend = m_dataOut.takeFirst();

                m_serialPort->write(dataSend);
                m_serialPort->waitForBytesWritten(5);

            }
        }
        else if(m_btSocket->isOpen())
        {
            if(!m_dataOut.isEmpty() && m_btSocket->isWritable())
            {
                QByteArray dataSend = m_dataOut.takeFirst();

                m_btSocket->write(dataSend);
                m_btSocket->waitForBytesWritten(5);
            }
        }
        QThread::msleep(1);
    }
}

void CommunicationThread::sendData(QByteArray data)
{
    QByteArray dataOut;

    dataOut.append(DATA_START_MESSAGE_FLAG);
    dataOut.append(DATA_START_MESSAGE_FLAG);

    dataOut.append(data.size());

    dataOut.append(data);

    dataOut.append(DATA_END_MESSAGE_FLAG);
    dataOut.append(DATA_END_MESSAGE_FLAG);

    if(m_dataOut.size() > MAX_OUT_BUFFER)
    {
        m_dataOut.takeLast();
    }
    m_dataOut.append(dataOut);
}

void CommunicationThread::openSerialPort(QString portName)
{
    if(!m_serialPort->isOpen())
    {
        m_serialPort->setPortName(portName);

        if(m_serialPort->open(QIODevice::ReadWrite))
        {
            emit serialPortOpened();
            this->start();
        }
    }
}

void CommunicationThread::openBTSocket(const QBluetoothDeviceInfo &device)
{
    m_btSocket.reset(new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this));

    connect(m_btSocket.data(), &QBluetoothSocket::connected,
            this, &CommunicationThread::serialPortOpened);

    connect(m_btSocket.data(), &QBluetoothSocket::disconnected,
            this, &CommunicationThread::serialPortClosed);

    m_btSocket->connectToService(QBluetoothAddress(device.address()),
                                 QBluetoothUuid(QBluetoothUuid::SerialPort));

    this->start();
}

void CommunicationThread::closeSerialPort()
{
    if(m_serialPort && m_serialPort->isOpen())
    {
        m_quit = true;
        m_serialPort->clear();
        m_serialPort->close();

        emit serialPortClosed();
    }
}

void CommunicationThread::closeBTSocket()
{
    if(m_btSocket && m_btSocket->isOpen())
    {
        m_quit = true;
        m_btSocket->disconnectFromService();
    }
}
