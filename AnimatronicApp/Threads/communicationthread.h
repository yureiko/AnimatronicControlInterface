/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#ifndef COMMUNICATIONTHREAD_H
#define COMMUNICATIONTHREAD_H

#include <QThread>
#include <QSerialPort>
#include <QObject>
#include <QByteArray>
#include <QBluetoothSocket>

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

    void openBTSocket(const QBluetoothDeviceInfo &device);

    /**
     * @brief closes the selected serial port
     * @param portName
     */
    void closeSerialPort();

    void closeBTSocket();
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
    QScopedPointer<QBluetoothSocket> m_btSocket;
    bool m_quit;
};

#endif // COMMUNICATIONTHREAD_H
