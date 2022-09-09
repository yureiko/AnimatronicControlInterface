#include "slidercontroller.h"
#include <QDebug>

SliderController::SliderController(QObject *parent)
    : QObject(parent)
{

}

void SliderController::onPositionChanged(float position)
{
    m_sliderPosition = position;

    emit sliderPositionChanged();
}

float SliderController::sliderPosition() const
{
    return m_sliderPosition;
}
