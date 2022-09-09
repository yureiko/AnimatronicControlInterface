#ifndef MOUTHCONTROL_H
#define MOUTHCONTROL_H

#include <QObject>
#include <QTimer>

class MouthControl : public QObject
{
    Q_OBJECT
public:
    explicit MouthControl(QObject *parent = nullptr);

    float positionDegrees() const;

public slots:
    void setPositionDegrees(float newPosition);

signals:
    void positionDegreesChanged(float positionDegrees);

private:
    void breathe();

    float m_positionDegrees;
    QTimer *m_breatheTimer;
    float m_breatheOffsetDegrees;
    bool m_isBreathOffsetIncrement;
};

#endif // MOUTHCONTROL_H
