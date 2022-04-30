#include "communicationthread.h"

#define DATA_START_MESSAGE_FLAG 0xAA
#define DATA_END_MESSAGE_FLAG 0x55

CommunicationThread::CommunicationThread(QObject *parent)
    : QThread(parent),
      m_serialPort(new QSerialPort()),
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

    while(!m_quit)
    {
        if(!m_dataOut.isEmpty() && m_serialPort->isWritable())
        {
            QByteArray dataSend = m_dataOut.first();
            m_dataOut.removeFirst();
            m_serialPort->write(dataSend);
            m_serialPort->waitForBytesWritten(-1);
        }
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
