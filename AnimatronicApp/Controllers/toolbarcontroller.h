#ifndef TOOLBARCONTROLLER_H
#define TOOLBARCONTROLLER_H

#include <QObject>
#include <QVariantList>
#include <QSerialPortInfo>
#include <QTimer>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth>
#include <QPointer>

/**
 * @brief The ToolBarController class provides a controller for a ToolBar view
 */
class ToolBarController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList ui_availablePortsList READ availablePortsList NOTIFY availablePortsListChanged)
    Q_PROPERTY(QString ui_serialPortOpenButtonText READ serialPortOpenButtonText NOTIFY serialPortOpenButtonTextChanged)
    Q_PROPERTY(bool ui_btConnectionCheckBoxEnabled READ btConnectionCheckBoxEnabled NOTIFY btConnectionCheckBoxEnabledChanged)

public:
    /**
     * @brief Constructor
     * @param parent
     */
    explicit ToolBarController(QObject *parent = nullptr);

    /**
     * @brief returns the available serial ports list
     * @return QVariantList
     */
    const QVariantList &availablePortsList() const;

    /**
     * @brief returns the serial port button text
     * @return QString
     */
    const QString &serialPortOpenButtonText() const;

    /**
     * @brief returns the state of current serial port
     * @return bool
     */
    bool isSerialPortOpen() const;

    /**
     * @brief set serial port open state
     * @param newIsSerialPortOpen
     */
    void setIsSerialPortOpen(bool newIsSerialPortOpen);

    bool btConnectionCheckBoxEnabled() const;

signals:
    /**
     * @brief notifies when available ports list changed
     */
    void availablePortsListChanged();

    /**
     * @brief notifies when serial port open button text changed
     */
    void serialPortOpenButtonTextChanged();

    /**
     * @brief notifies when serial port open has requested
     * @param portName
     */
    void serialPortOpenRequested(QString portName);

    void btDeviceConnectionRequested(QBluetoothDeviceInfo deviceInfo);

    /**
     * @brief notifies when serial port close has requested
     * @param portName
     */
    void serialPortCloseRequested();

    void btDeviceDisconnectionRequested();

    void btConnectionCheckBoxEnabledChanged();

public slots:

    /**
     * @brief slot triggered when open serial port has pressed
     * @param currentIndex
     */
    Q_INVOKABLE void onOpenSerialPortPressed(int currentIndex);

    Q_INVOKABLE void onBTEnabledPressed(bool checked);

private:

    void bluetoothDevicedDiscovered(const QBluetoothDeviceInfo &newDevice);
    /**
     * @brief scan for serial ports
     */
    void scanSerialPorts();

    QVariantList m_availablePortsList;
    QVariantList m_availableBTDevicesList;
    QHash<QString,QBluetoothDeviceInfo> m_bluetoothDeviceInfoTable;
    QPointer<QBluetoothDeviceDiscoveryAgent> m_bluetoothDeviceDiscoveryAgent;
    QString m_serialPortOpenButtonText;
    bool m_isSerialPortOpen;
    bool m_btEnabled;
    bool m_btConnectionCheckBoxEnabled;
    QTimer *m_timer;
};

#endif // TOOLBARCONTROLLER_H
