#ifndef COMMUNICATIONTHREAD_H
#define COMMUNICATIONTHREAD_H

#include <QThread>
#include <QSerialPort>
#include <QObject>

class CommunicationThread : public QThread
{
    Q_OBJECT
public:
    explicit CommunicationThread(QObject *parent = nullptr);

    void run() override;

public slots:
    void openSerialPort(QString portName);

    void closeSerialPort();

signals:
    void serialPortOpened();
    void serialPortClosed();

private:
    QSerialPort *m_serialPort;
};

#endif // COMMUNICATIONTHREAD_H
