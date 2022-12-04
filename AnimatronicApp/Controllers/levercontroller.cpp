/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#include "levercontroller.h"

#include <QVector2D>
#include <QDebug>
#include <QtMath>

LeverController::LeverController(QObject *parent)
    : QObject(parent),
      m_rotation(0.0)
{

}

qreal LeverController::rotation() const
{
    return m_rotation;
}

void LeverController::setRotation(QVariantList newPosition)
{
    QVector2D position = {newPosition.first().toFloat(), newPosition.last().toFloat()};

    m_rotation -= position.y();

    if(m_rotation > 10.0)
    {
        m_rotation = 10.0;
    }
    else if(m_rotation < -10.0)
    {
        m_rotation = -10.0;
    }

    emit rotationChanged();
}
