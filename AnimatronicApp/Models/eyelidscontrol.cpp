#include "eyelidscontrol.h"

#define SUPERIOR_MAX_DEG_VALUE 100.f
#define SUPERIOR_MIN_DEG_VALUE 0.f

#define INFERIOR_MAX_DEG_VALUE 100.f
#define INFERIOR_MIN_DEG_VALUE 0.f

EyelidsControl::EyelidsControl(QObject *parent)
    : QObject(parent),
      m_positionDegrees({0.f,0.f}),
      m_positionCenterOffsetDegrees({0.f,0.f})

{

}

QPair<float,float> EyelidsControl::positionDegrees() const
{
    return QPair<float,float>({m_positionDegrees.first + 0.15f*m_positionCenterOffsetDegrees.first,
            m_positionDegrees.second - 0.15f*m_positionCenterOffsetDegrees.second});
}

void EyelidsControl::setPositionDegrees(QPair<float,float> newPosition)
{
    m_positionDegrees = {(newPosition.first * (SUPERIOR_MAX_DEG_VALUE - SUPERIOR_MIN_DEG_VALUE) + SUPERIOR_MIN_DEG_VALUE),
                  (newPosition.second * (INFERIOR_MAX_DEG_VALUE - INFERIOR_MIN_DEG_VALUE) + INFERIOR_MIN_DEG_VALUE)};

    emit positionDegreesChanged(m_positionDegrees);
}

void EyelidsControl::setPositionCenterYOffsetDegrees(float yOffset)
{
    m_positionCenterOffsetDegrees =  {(((yOffset + 1.f)/2.f) * (SUPERIOR_MAX_DEG_VALUE - SUPERIOR_MIN_DEG_VALUE)) + SUPERIOR_MIN_DEG_VALUE,
                  (((yOffset + 1.f)/2.f) * (INFERIOR_MAX_DEG_VALUE - INFERIOR_MIN_DEG_VALUE)) + INFERIOR_MIN_DEG_VALUE};

    QPair<float,float> outputPosition = {m_positionDegrees.first + 0.1f*m_positionCenterOffsetDegrees.first,
                                         m_positionDegrees.second - 0.1f*m_positionCenterOffsetDegrees.second};

    emit positionDegreesChanged(outputPosition);
}
