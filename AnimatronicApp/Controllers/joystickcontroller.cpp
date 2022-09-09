#include "joystickcontroller.h"
#include <QDebug>
#include <QVector2D>

JoystickController::JoystickController(QObject *parent)
    : QObject(parent),
      m_joystickPosition(QPointF())
{

}

QPointF JoystickController::joystickPosition() const
{
    return m_joystickPosition;
}

void JoystickController::setJoystickPosition(QVariantList newJoystickPosition)
{
    QVector2D position = {newJoystickPosition.first().toFloat(), newJoystickPosition.last().toFloat()};

    if(position.length() > 1)
    {
         m_joystickPosition = position.normalized().toPointF();
    }
    else
    {
         m_joystickPosition = position.toPointF();
    }

    emit joystickPositionChanged();
}
