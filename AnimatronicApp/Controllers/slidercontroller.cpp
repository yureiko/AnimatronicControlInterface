/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

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
