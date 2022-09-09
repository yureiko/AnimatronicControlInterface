#ifndef COMMUNICATIONTHREAD_H
#define COMMUNICATIONTHREAD_H

#include <QThread>
#include <QSerialPort>
#include <QObject>
#include <QByteArray>

/**
 * @brief The CommunicationThread class provides the bridge between the hardware controller and the application
 */
class CommunicationThread : public QThread
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param parent
     */
    explicit CommunicationThread(QObject *parent = nullptr);

    /**
     * @brief main loop
     */
    void run() override;

    /**
     * @brief sends data to the target
     * @param data
     */
    void sendData(QByteArray data);

public slots:
    /**
     * @brief opens the selected serial port
     * @param portName
     */
    void openSerialPort(QString portName);

    /**
     * @brief closes the selected serial port
     * @param portName
     */
    void closeSerialPort();

signals:
    /**
     * @brief notifies when the serial port opened
     */
    void serialPortOpened();

    /**
     * @brief notifies when the serial port closed
     */
    void serialPortClosed();

private:
    QSerialPort *m_serialPort;
    QVector<QByteArray> m_dataOut;
    bool m_quit;
};

#endif // COMMUNICATIONTHREAD_H
