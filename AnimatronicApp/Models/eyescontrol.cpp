/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#include "eyescontrol.h"

#define HORIZONTAL_MAX_DEG_VALUE 135
#define HORIZONTAL_MIN_DEG_VALUE 45

#define VERTICAL_MAX_DEG_VALUE 145
#define VERTICAL_MIN_DEG_VALUE 35

EyesControl::EyesControl(QObject *parent)
    : QObject(parent),
      m_positionDegrees(QPointF(0.f, 0.f))
{

}

QPointF EyesControl::positionDegrees() const
{
    return m_positionDegrees;
}

void EyesControl::setPositionDegrees(QPointF newPosition)
{
    m_positionDegrees = {(((newPosition.x() + 1.0)/2.0) * (HORIZONTAL_MAX_DEG_VALUE - HORIZONTAL_MIN_DEG_VALUE)) + HORIZONTAL_MIN_DEG_VALUE,
                  (((newPosition.y() + 1.0)/2.0) * (VERTICAL_MAX_DEG_VALUE - VERTICAL_MIN_DEG_VALUE)) + VERTICAL_MIN_DEG_VALUE};

    emit positionDegreesChanged(m_positionDegrees);
}
