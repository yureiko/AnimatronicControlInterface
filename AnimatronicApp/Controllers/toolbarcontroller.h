#ifndef TOOLBARCONTROLLER_H
#define TOOLBARCONTROLLER_H

#include <QObject>
#include <QVariantList>
#include <QSerialPortInfo>
#include <QTimer>

class ToolBarController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList ui_availablePortsList READ availablePortsList NOTIFY availablePortsListChanged)
    Q_PROPERTY(QString ui_serialPortOpenButtonText READ serialPortOpenButtonText NOTIFY serialPortOpenButtonTextChanged)
    //Q_PROPERTY(bool ui_serialPortControlOpen READ serialPortControlOpen NOTIFY serialPortControlOpenChanged)
public:
    explicit ToolBarController(QObject *parent = nullptr);

    const QVariantList &availablePortsList() const;

    const QString &serialPortOpenButtonText() const;

    bool serialPortControlOpen() const;

    bool isSerialPortOpen() const;
    void setIsSerialPortOpen(bool newIsSerialPortOpen);

signals:
    void availablePortsListChanged();
    void serialPortOpenButtonTextChanged();

    void serialPortOpenRequested(QString portName);
    void serialPortCloseRequested();

public slots:

    Q_INVOKABLE void onOpenSerialPortPressed(int currentIndex);

private:

    void scanSerialPorts();

    QVariantList m_availablePortsList;
    QString m_serialPortOpenButtonText;
    bool m_isSerialPortOpen;
    QTimer *m_timer;
};

#endif // TOOLBARCONTROLLER_H
