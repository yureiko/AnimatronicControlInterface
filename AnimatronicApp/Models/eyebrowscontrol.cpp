#include "eyebrowscontrol.h"

#define MAX_ROTATION_DEG_VALUE 10.f
#define MIN_ROTATION_DEG_VALUE -10.f

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
    qreal rotationDegrees = rotation;

    if(rotationDegrees > MAX_ROTATION_DEG_VALUE)
    {
        rotationDegrees = 10.f;
    }
    else if(rotationDegrees < MIN_ROTATION_DEG_VALUE)
    {
        rotationDegrees = -10.f;
    }
    m_leftRotationDegrees = rotationDegrees + CENTER_DEG_VALUE;

    emit rotationDegreesChanged(m_leftRotationDegrees);
}

qreal EyebrowsControl::rightRotationDegrees() const
{
    return m_rightRotationDegrees;
}

void EyebrowsControl::setRightRotationDegrees(qreal rotation)
{
    qreal rotationDegrees = rotation;

    if(rotationDegrees > MAX_ROTATION_DEG_VALUE)
    {
        rotationDegrees = 10.f;
    }
    else if(rotationDegrees < MIN_ROTATION_DEG_VALUE)
    {
        rotationDegrees = -10.f;
    }
    m_rightRotationDegrees = rotationDegrees + CENTER_DEG_VALUE;

    emit rotationDegreesChanged(m_leftRotationDegrees);
}
