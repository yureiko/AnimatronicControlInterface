#ifndef EMOTIONSCONTROL_H
#define EMOTIONSCONTROL_H

#include "eyescontrol.h"
#include "eyelidscontrol.h"
#include "eyebrowscontrol.h"
#include "mouthcontrol.h"
#include "Controllers/emotionsbuttongradecontroller.h"
#include <QObject>

/**
 * @brief The EmotionsControl class provides a model to manage the animatronic
 * emotions
 */
class EmotionsControl : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief EmotionsControl contructor
     * @param parent
     */
    explicit EmotionsControl(QObject *parent = nullptr);

    /**
     * @brief Default setter
     * @param newEyesControl
     */
    void setEyesControl(EyesControl *newEyesControl);

    /**
     * @brief Default setter
     * @param newEyelidsControl
     */
    void setEyelidsControl(EyelidsControl *newEyelidsControl);

    /**
     * @brief Default setter
     * @param newEyebrowsControl
     */
    void setEyebrowsControl(EyebrowsControl *newEyebrowsControl);

    /**
     * @brief Default setter
     * @param newMouthControl
     */
    void setMouthControl(MouthControl *newMouthControl);

    /**
     * @brief Default setter
     * @param newEmotionsController
     */
    void setEmotionsController(EmotionsButtonGradeController *newEmotionsController);

signals:

private slots:
    /**
     * @brief onEmotionChanged
     */
    void onEmotionChanged();
private:

    /**
     * @brief Sets parts to neutral position
     */
    void startNeutralEmotion();

    /**
     * @brief Sets parts to happy position
     */
    void startHappyEmotion();

    /**
     * @brief Sets parts to scared position
     */
    void startScaredEmotion();

    /**
     * @brief Sets parts to angry position
     */
    void startAngryEmotion();

    /**
     * @brief Sets parts to sleepy position
     */
    void startSleepyEmotion();

    /**
     * @brief Sets parts to neutral position
     */
    void startSuspiciousEmotion();

    EyesControl *m_eyesControl;
    EyelidsControl *m_eyelidsControl;
    EyebrowsControl *m_eyebrowsControl;
    MouthControl *m_mouthControl;

    EmotionsButtonGradeController *m_emotionsController;
};

#endif // EMOTIONSCONTROL_H
