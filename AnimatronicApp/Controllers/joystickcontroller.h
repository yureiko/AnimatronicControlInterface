#ifndef JOYSTICKCONTROLLER_H
#define JOYSTICKCONTROLLER_H

#include <QObject>
#include <QPointF>
#include <QVariantList>

class JoystickController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPointF ui_joystickPosition READ joystickPosition NOTIFY joystickPositionChanged)

public:
    explicit JoystickController(QObject *parent = nullptr);

    QPointF joystickPosition() const;

public slots:
    void setJoystickPosition(QVariantList newJoystickPosition);

signals:

    void joystickPositionChanged();

private:
    QPointF m_joystickPosition;

};

#endif // JOYSTICKCONTROLLER_H
