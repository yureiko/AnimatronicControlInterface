/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#include "eyelidscontrol.h"
#include <QRandomGenerator>

#define SUPERIOR_MAX_DEG_VALUE 100.f
#define SUPERIOR_MIN_DEG_VALUE 0.f

#define INFERIOR_MAX_DEG_VALUE 100.f
#define INFERIOR_MIN_DEG_VALUE 0.f

EyelidsControl::EyelidsControl(QObject *parent)
    : QObject(parent),
      m_positionDegrees({SUPERIOR_MAX_DEG_VALUE*0.7, INFERIOR_MAX_DEG_VALUE*0.7}),
      m_positionCenterOffsetDegrees({0.f,0.f}),
      m_blinkTimer(new QTimer(this)),
      m_isBlinking(true)
{
    m_blinkTimer->setSingleShot(true);
    connect(m_blinkTimer, &QTimer::timeout, this, &EyelidsControl::blink);
    m_blinkTimer->start(5000);
}

QPair<float,float> EyelidsControl::positionDegrees() const
{
    if(m_isBlinking)
    {
        return QPair<float,float>({m_positionDegrees.first + 0.15f*m_positionCenterOffsetDegrees.first,
                m_positionDegrees.second - 0.15f*m_positionCenterOffsetDegrees.second});
    }
    else
    {
        return {0.f, 0.f};
    }
}

void EyelidsControl::setPositionDegrees(QPair<float,float> newPosition)
{
    m_positionDegrees = {(newPosition.first * (SUPERIOR_MAX_DEG_VALUE - SUPERIOR_MIN_DEG_VALUE) + SUPERIOR_MIN_DEG_VALUE),
                  (newPosition.second * (INFERIOR_MAX_DEG_VALUE - INFERIOR_MIN_DEG_VALUE) + INFERIOR_MIN_DEG_VALUE)};

    emit positionDegreesChanged(m_positionDegrees);
}

void EyelidsControl::blink()
{
    if(m_isBlinking)
    {
        m_blinkTimer->start(200);
    }
    else
    {
        m_blinkTimer->start(2000 + QRandomGenerator::global()->generateDouble() * 3000);
    }

    m_isBlinking = !m_isBlinking;
}

void EyelidsControl::setPositionCenterYOffsetDegrees(float yOffset)
{
    m_positionCenterOffsetDegrees =  {(((yOffset + 1.f)/2.f) * (SUPERIOR_MAX_DEG_VALUE - SUPERIOR_MIN_DEG_VALUE)) + SUPERIOR_MIN_DEG_VALUE,
                  (((yOffset + 1.f)/2.f) * (INFERIOR_MAX_DEG_VALUE - INFERIOR_MIN_DEG_VALUE)) + INFERIOR_MIN_DEG_VALUE};

    QPair<float,float> outputPosition = {m_positionDegrees.first + 0.1f*m_positionCenterOffsetDegrees.first,
                                         m_positionDegrees.second - 0.1f*m_positionCenterOffsetDegrees.second};

    emit positionDegreesChanged(outputPosition);
}
