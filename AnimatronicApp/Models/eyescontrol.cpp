#include "eyescontrol.h"

#define HORIZONTAL_MAX_DEG_VALUE 135
#define HORIZONTAL_MIN_DEG_VALUE 45

#define VERTICAL_MAX_DEG_VALUE 135
#define VERTICAL_MIN_DEG_VALUE 45

EyesControl::EyesControl(QObject *parent)
    : QObject{parent}
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
