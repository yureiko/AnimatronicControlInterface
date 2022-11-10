#ifndef EMOTIONSCONTROL_H
#define EMOTIONSCONTROL_H

#include "eyescontrol.h"
#include "eyelidscontrol.h"
#include "eyebrowscontrol.h"
#include "mouthcontrol.h"
#include "Controllers/emotionsbuttongradecontroller.h"
#include <QObject>

class EmotionsControl : public QObject
{
    Q_OBJECT
public:
    explicit EmotionsControl(QObject *parent = nullptr);

    void setEyesControl(EyesControl *newEyesControl);
    void setEyelidsControl(EyelidsControl *newEyelidsControl);
    void setEyebrowsControl(EyebrowsControl *newEyebrowsControl);
    void setMouthControl(MouthControl *newMouthControl);

    void setEmotionsController(EmotionsButtonGradeController *newEmotionsController);

signals:

private slots:
    void onEmotionChanged();
private:

    void startNeutralEmotion();

    void startHappyEmotion();

    void startScaredEmotion();

    void startAngryEmotion();

    void startSleepyEmotion();

    void startSuspiciousEmotion();

    EyesControl *m_eyesControl;
    EyelidsControl *m_eyelidsControl;
    EyebrowsControl *m_eyebrowsControl;
    MouthControl *m_mouthControl;

    EmotionsButtonGradeController *m_emotionsController;
};

#endif // EMOTIONSCONTROL_H
