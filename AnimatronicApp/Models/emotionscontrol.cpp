/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#include "emotionscontrol.h"

EmotionsControl::EmotionsControl(QObject *parent)
    : QObject(parent)
{

}

void EmotionsControl::setEyesControl(EyesControl *newEyesControl)
{
    m_eyesControl = newEyesControl;
}

void EmotionsControl::setEyelidsControl(EyelidsControl *newEyelidsControl)
{
    m_eyelidsControl = newEyelidsControl;
}

void EmotionsControl::setEyebrowsControl(EyebrowsControl *newEyebrowsControl)
{
    m_eyebrowsControl = newEyebrowsControl;
}

void EmotionsControl::setMouthControl(MouthControl *newMouthControl)
{
    m_mouthControl = newMouthControl;
}

void EmotionsControl::setEmotionsController(EmotionsButtonGradeController *newEmotionsController)
{
    m_emotionsController = newEmotionsController;

    connect(m_emotionsController, &EmotionsButtonGradeController::emotionButtonsCheckedChanged,
            this, &EmotionsControl::onEmotionChanged);
}

void EmotionsControl::onEmotionChanged()
{
    if(m_emotionsController->neutralEmotionChecked())
    {
        startNeutralEmotion();
    }
    else if(m_emotionsController->happyEmotionChecked())
    {
        startHappyEmotion();
    }
    else if(m_emotionsController->scaredEmotionChecked())
    {
        startScaredEmotion();
    }
    else if(m_emotionsController->angryEmotionChecked())
    {
        startAngryEmotion();
    }
    else if(m_emotionsController->sleepyEmotionChecked())
    {
        startSleepyEmotion();
    }
    else if(m_emotionsController->suspiciousEmotionChecked())
    {
        startSuspiciousEmotion();
    }
}

void EmotionsControl::startNeutralEmotion()
{
    m_eyesControl->setPositionDegrees({0.f, 0.f});
    m_eyelidsControl->setPositionDegrees({0.8f, 0.8f});
    m_eyebrowsControl->setLeftRotationDegrees(0.f);
    m_eyebrowsControl->setRightRotationDegrees(0.f);
    m_mouthControl->setPositionDegrees(1.f);
}

void EmotionsControl::startHappyEmotion()
{
    m_eyesControl->setPositionDegrees({0.f, 0.f});
    m_eyelidsControl->setPositionDegrees({0.9f, 0.6f});
    m_eyebrowsControl->setLeftRotationDegrees(-8.f);
    m_eyebrowsControl->setRightRotationDegrees(-8.f);
    m_mouthControl->setPositionDegrees(0.8f);
}

void EmotionsControl::startScaredEmotion()
{
    m_eyesControl->setPositionDegrees({0.f, 0.f});
    m_eyelidsControl->setPositionDegrees({1.0f, 1.0f});
    m_eyebrowsControl->setLeftRotationDegrees(-20.f);
    m_eyebrowsControl->setRightRotationDegrees(-20.f);
    m_mouthControl->setPositionDegrees(0.2f);
}

void EmotionsControl::startAngryEmotion()
{
    m_eyesControl->setPositionDegrees({0.f, 0.5f});
    m_eyelidsControl->setPositionDegrees({0.5f, 0.9f});
    m_eyebrowsControl->setLeftRotationDegrees(20.f);
    m_eyebrowsControl->setRightRotationDegrees(20.f);
    m_mouthControl->setPositionDegrees(1.0f);
}

void EmotionsControl::startSleepyEmotion()
{
    m_eyesControl->setPositionDegrees({0.f, 0.9f});
    m_eyelidsControl->setPositionDegrees({0.5f, 0.8f});
    m_eyebrowsControl->setLeftRotationDegrees(-10.f);
    m_eyebrowsControl->setRightRotationDegrees(-10.f);
    m_mouthControl->setPositionDegrees(0.0f);
}

void EmotionsControl::startSuspiciousEmotion()
{
    m_eyesControl->setPositionDegrees({0.f, 0.0f});
    m_eyelidsControl->setPositionDegrees({0.6f, 0.6f});
    m_eyebrowsControl->setLeftRotationDegrees(20.f);
    m_eyebrowsControl->setRightRotationDegrees(-20.f);
    m_mouthControl->setPositionDegrees(1.0f);
}
