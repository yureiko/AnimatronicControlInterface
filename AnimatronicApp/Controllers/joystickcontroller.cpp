/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#include "joystickcontroller.h"
#include <QDebug>
#include <QVector2D>

JoystickController::JoystickController(QObject *parent)
    : QObject(parent),
      m_joystickPosition(QPointF(0.f,0.f))
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
