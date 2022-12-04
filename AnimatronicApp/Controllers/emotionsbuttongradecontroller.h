/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#ifndef EMOTIONSBUTTONGRADECONTROLLER_H
#define EMOTIONSBUTTONGRADECONTROLLER_H

#include <QHash>
#include <QObject>

/**
 * @brief The EmotionsButtonGradeController class provides a controller for button grade view
 */
class EmotionsButtonGradeController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool ui_neutralEmotionChecked READ neutralEmotionChecked NOTIFY emotionButtonsCheckedChanged)
    Q_PROPERTY(bool ui_happyEmotionChecked READ happyEmotionChecked NOTIFY emotionButtonsCheckedChanged)
    Q_PROPERTY(bool ui_scaredEmotionChecked READ scaredEmotionChecked NOTIFY emotionButtonsCheckedChanged)
    Q_PROPERTY(bool ui_angryEmotionChecked READ angryEmotionChecked NOTIFY emotionButtonsCheckedChanged)
    Q_PROPERTY(bool ui_sleepyEmotionChecked READ sleepyEmotionChecked NOTIFY emotionButtonsCheckedChanged)
    Q_PROPERTY(bool ui_suspiciousEmotionChecked READ suspiciousEmotionChecked NOTIFY emotionButtonsCheckedChanged)

public:
    /**
     * @brief EmotionsButtonGradeController constructor
     * @param parent
     */
    explicit EmotionsButtonGradeController(QObject *parent = nullptr);

    /**
     * @brief return neutral emotion checked state
     * @return bool
     */
    bool neutralEmotionChecked() const;

    /**
     * @brief return happy emotion checked state
     * @return bool
     */
    bool happyEmotionChecked() const;

    /**
     * @brief return scared emotion checked state
     * @return bool
     */
    bool scaredEmotionChecked() const;

    /**
     * @brief return angry emotion checked state
     * @return bool
     */
    bool angryEmotionChecked() const;

    /**
     * @brief return sleepy emotion checked state
     * @return bool
     */
    bool sleepyEmotionChecked() const;

    /**
     * @brief return suspicious emotion checked state
     * @return bool
     */
    bool suspiciousEmotionChecked() const;

signals:

    /**
     * @brief emotionButtonsCheckedChanged
     */
    void emotionButtonsCheckedChanged();

public slots:

    /**
     * @brief Process neutral emotion pressed
     */
    void onNeutralEmotionPressed();

    /**
     * @brief Process happy emotion pressed
     */
    void onHappyEmotionPressed();

    /**
     * @brief Process scared emotion pressed
     */
    void onScaredEmotionPressed();

    /**
     * @brief Process angry emotion pressed
     */
    void onAngryEmotionPressed();

    /**
     * @brief Process sleepy emotion pressed
     */
    void onSleepyEmotionPressed();

    /**
     * @brief Process suspicious emotion pressed
     */
    void onSuspiciousEmotionPressed();

private:

    QHash<QString, bool> m_emotionButtonsStates;
    void clearCheckedButtons();
};

#endif // EMOTIONSBUTTONGRADECONTROLLER_H
