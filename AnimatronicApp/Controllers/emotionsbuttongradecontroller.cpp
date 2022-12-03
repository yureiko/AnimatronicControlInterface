#include "emotionsbuttongradecontroller.h"

EmotionsButtonGradeController::EmotionsButtonGradeController(QObject *parent)
    : QObject(parent)
{
    m_emotionButtonsStates.insert("neutral", false);
    m_emotionButtonsStates.insert("happy", false);
    m_emotionButtonsStates.insert("scared", false);
    m_emotionButtonsStates.insert("angry", false);
    m_emotionButtonsStates.insert("sleepy", false);
    m_emotionButtonsStates.insert("suspicious", false);
}

bool EmotionsButtonGradeController::neutralEmotionChecked() const
{
    return m_emotionButtonsStates.value("neutral", false);
}

bool EmotionsButtonGradeController::happyEmotionChecked() const
{
    return m_emotionButtonsStates.value("happy", false);
}

bool EmotionsButtonGradeController::scaredEmotionChecked() const
{
    return m_emotionButtonsStates.value("scared", false);
}

bool EmotionsButtonGradeController::angryEmotionChecked() const
{
    return m_emotionButtonsStates.value("angry", false);
}

bool EmotionsButtonGradeController::sleepyEmotionChecked() const
{
    return m_emotionButtonsStates.value("sleepy", false);
}

bool EmotionsButtonGradeController::suspiciousEmotionChecked() const
{
    return m_emotionButtonsStates.value("suspicious", false);
}

void EmotionsButtonGradeController::onNeutralEmotionPressed()
{
    clearCheckedButtons();
    m_emotionButtonsStates.insert("neutral", true);
    emit emotionButtonsCheckedChanged();
}

void EmotionsButtonGradeController::onHappyEmotionPressed()
{
    clearCheckedButtons();
    m_emotionButtonsStates.insert("happy", true);
    emit emotionButtonsCheckedChanged();
}

void EmotionsButtonGradeController::onScaredEmotionPressed()
{
    clearCheckedButtons();
    m_emotionButtonsStates.insert("scared", true);
    emit emotionButtonsCheckedChanged();
}

void EmotionsButtonGradeController::onAngryEmotionPressed()
{
    clearCheckedButtons();
    m_emotionButtonsStates.insert("angry", true);
    emit emotionButtonsCheckedChanged();
}

void EmotionsButtonGradeController::onSleepyEmotionPressed()
{
    clearCheckedButtons();
    m_emotionButtonsStates.insert("sleepy", true);
    emit emotionButtonsCheckedChanged();
}

void EmotionsButtonGradeController::onSuspiciousEmotionPressed()
{
    clearCheckedButtons();
    m_emotionButtonsStates.insert("suspicious", true);
    emit emotionButtonsCheckedChanged();
}

void EmotionsButtonGradeController::clearCheckedButtons()
{
    foreach(auto key, m_emotionButtonsStates.keys())
    {
        m_emotionButtonsStates.insert(key, false);
    }
}
