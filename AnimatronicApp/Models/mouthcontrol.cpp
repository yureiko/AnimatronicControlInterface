#include "mouthcontrol.h"

#define MAX_DEG_VALUE 30.f
#define MIN_DEG_VALUE 0.f

MouthControl::MouthControl(QObject *parent)
    :QObject(parent)
{

}

float MouthControl::positionDegrees() const
{
    return m_positionDegrees;
}

void MouthControl::setPositionDegrees(float newPosition)
{
    m_positionDegrees = ((1.0 - newPosition) * (MAX_DEG_VALUE - MIN_DEG_VALUE) + MIN_DEG_VALUE);

    emit positionDegreesChanged(m_positionDegrees);
}
