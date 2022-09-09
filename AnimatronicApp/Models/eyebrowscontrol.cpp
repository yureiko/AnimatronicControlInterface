#include "eyebrowscontrol.h"

#define MAX_ROTATION_DEG_VALUE 20.f
#define MIN_ROTATION_DEG_VALUE -20.f

#define CENTER_DEG_VALUE 90.f

EyebrowsControl::EyebrowsControl(QObject *parent)
    : QObject(parent),
    m_leftRotationDegrees(0.0)
{

}

qreal EyebrowsControl::leftRotationDegrees() const
{
    return m_leftRotationDegrees;
}

void EyebrowsControl::setLeftRotationDegrees(qreal rotation)
{
    qreal rotationDegrees = 2*rotation;

    if(rotationDegrees > MAX_ROTATION_DEG_VALUE)
    {
        rotationDegrees = MAX_ROTATION_DEG_VALUE;
    }
    else if(rotationDegrees < MIN_ROTATION_DEG_VALUE)
    {
        rotationDegrees = MIN_ROTATION_DEG_VALUE;
    }
    m_leftRotationDegrees = -rotationDegrees + CENTER_DEG_VALUE;

    emit rotationDegreesChanged(m_leftRotationDegrees);
}

qreal EyebrowsControl::rightRotationDegrees() const
{
    return m_rightRotationDegrees;
}

QPair<float, float> EyebrowsControl::positionDegrees()
{
    return QPair<float, float>(leftRotationDegrees(), rightRotationDegrees());
}

void EyebrowsControl::setRightRotationDegrees(qreal rotation)
{
    qreal rotationDegrees = 2*rotation;

    if(rotationDegrees > MAX_ROTATION_DEG_VALUE)
    {
        rotationDegrees = MAX_ROTATION_DEG_VALUE;
    }
    else if(rotationDegrees < MIN_ROTATION_DEG_VALUE)
    {
        rotationDegrees = MIN_ROTATION_DEG_VALUE;
    }
    m_rightRotationDegrees = rotationDegrees + CENTER_DEG_VALUE;

    emit rotationDegreesChanged(m_leftRotationDegrees);
}
