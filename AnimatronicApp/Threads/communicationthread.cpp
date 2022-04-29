#include "communicationthread.h"

CommunicationThread::CommunicationThread(QObject *parent)
    : QThread(parent),
      m_serialPort(new QSerialPort())
{
}

void CommunicationThread::run()
{



}

void CommunicationThread::openSerialPort(QString portName)
{
    if(!m_serialPort->isOpen())
    {
        m_serialPort->setPortName(portName);
        m_serialPort->setBaudRate(115200);

        if(m_serialPort->open(QIODevice::ReadWrite))
        {
            emit serialPortOpened();
            return;
        }
    }
}

void CommunicationThread::closeSerialPort()
{
    if(m_serialPort && m_serialPort->isOpen())
    {
        m_serialPort->clear();
        m_serialPort->close();

        emit serialPortClosed();
    }
}
