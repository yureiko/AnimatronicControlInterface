#ifndef COMMUNICATIONTHREAD_H
#define COMMUNICATIONTHREAD_H

#include <QThread>
#include <QSerialPort>
#include <QObject>
#include <QByteArray>

class CommunicationThread : public QThread
{
    Q_OBJECT
public:
    explicit CommunicationThread(QObject *parent = nullptr);

    void run() override;

    void sendData(QByteArray data);

public slots:
    void openSerialPort(QString portName);

    void closeSerialPort();

signals:
    void serialPortOpened();
    void serialPortClosed();

private:
    QSerialPort *m_serialPort;
    QVector<QByteArray> m_dataOut;
    bool m_quit;
};

#endif // COMMUNICATIONTHREAD_H
