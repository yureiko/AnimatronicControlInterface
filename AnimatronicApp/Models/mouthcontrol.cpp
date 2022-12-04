/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#include "mouthcontrol.h"

#define MAX_DEG_VALUE 90.f
#define MIN_DEG_VALUE 5.f

#define MAX_BREATHE_POSITION_DEG 10.f
#define BREATHE_STEP_DEG 0.5f

MouthControl::MouthControl(QObject *parent)
    :QObject(parent),
      m_positionDegrees(MIN_DEG_VALUE),
      m_breatheTimer(new QTimer(this)),
      m_breatheOffsetDegrees(0.f),
      m_isBreathOffsetIncrement(true)
{
    connect(m_breatheTimer, &QTimer::timeout, this, &MouthControl::breathe);
    m_breatheTimer->start(100);
}

float MouthControl::positionDegrees() const
{
    return m_positionDegrees + m_breatheOffsetDegrees;
}

void MouthControl::setPositionDegrees(float newPosition)
{
    m_positionDegrees = ((1.0 - newPosition) * (MAX_DEG_VALUE - MIN_DEG_VALUE) + MIN_DEG_VALUE);

    emit positionDegreesChanged(m_positionDegrees);
}

void MouthControl::breathe()
{
    if(m_isBreathOffsetIncrement)
    {
        if(m_breatheOffsetDegrees < MAX_BREATHE_POSITION_DEG)
        {
            m_breatheOffsetDegrees += BREATHE_STEP_DEG;
        }
        else
        {
            m_isBreathOffsetIncrement = false;
        }
    }
    else
    {
        if(m_breatheOffsetDegrees > BREATHE_STEP_DEG)
        {
            m_breatheOffsetDegrees -= BREATHE_STEP_DEG;
        }
        else
        {
            m_isBreathOffsetIncrement = true;
        }
    }
}
