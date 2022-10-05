#ifndef EMOTIONSBUTTONGRADECONTROLLER_H
#define EMOTIONSBUTTONGRADECONTROLLER_H

#include <QHash>
#include <QObject>

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
    explicit EmotionsButtonGradeController(QObject *parent = nullptr);

    bool neutralEmotionChecked() const;
    bool happyEmotionChecked() const;
    bool scaredEmotionChecked() const;
    bool angryEmotionChecked() const;
    bool sleepyEmotionChecked() const;
    bool suspiciousEmotionChecked() const;

signals:

    void emotionButtonsCheckedChanged();

public slots:

    void onNeutralEmotionPressed();
    void onHappyEmotionPressed();
    void onScaredEmotionPressed();
    void onAngryEmotionPressed();
    void onSleepyEmotionPressed();
    void onSuspiciousEmotionPressed();

private:

    QHash<QString, bool> m_emotionButtonsStates;
    void clearCheckedButtons();
};

#endif // EMOTIONSBUTTONGRADECONTROLLER_H
