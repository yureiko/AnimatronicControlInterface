#ifndef TOOLBARCONTROLLER_H
#define TOOLBARCONTROLLER_H

#include <QObject>
#include <QVariantList>
#include <QSerialPortInfo>
#include <QTimer>

/**
 * @brief The ToolBarController class provides a controller for a ToolBar view
 */
class ToolBarController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList ui_availablePortsList READ availablePortsList NOTIFY availablePortsListChanged)
    Q_PROPERTY(QString ui_serialPortOpenButtonText READ serialPortOpenButtonText NOTIFY serialPortOpenButtonTextChanged)

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

    /**
     * @brief notifies when serial port close has requested
     * @param portName
     */
    void serialPortCloseRequested();

public slots:

    /**
     * @brief slot triggered when open serial port has pressed
     * @param currentIndex
     */
    Q_INVOKABLE void onOpenSerialPortPressed(int currentIndex);

private:

    /**
     * @brief scan for serial ports
     */
    void scanSerialPorts();

    QVariantList m_availablePortsList;
    QString m_serialPortOpenButtonText;
    bool m_isSerialPortOpen;
    QTimer *m_timer;
};

#endif // TOOLBARCONTROLLER_H
