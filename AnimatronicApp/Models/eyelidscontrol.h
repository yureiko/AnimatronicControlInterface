#ifndef EYELIDSCONTROL_H
#define EYELIDSCONTROL_H

#include <QObject>
#include <QTimer>

class EyelidsControl : public QObject
{
    Q_OBJECT
public:
    explicit EyelidsControl(QObject *parent = nullptr);

    QPair<float,float> positionDegrees() const;

    void setPositionCenterYOffsetDegrees(float yOffset);

public slots:
    void setPositionDegrees(QPair<float,float> newPosition);

signals:
    void positionDegreesChanged(QPair<float,float> positionDegrees);

private:

    void blink();

    QPair<float,float> m_positionDegrees;
    QPair<float,float> m_positionCenterOffsetDegrees;

    QTimer *m_blinkTimer;
    QPair<float,float> m_lastPositionDegrees;
    QPair<float,float> m_lastPositionCenterOffsetDegrees;
    bool m_isBlinking;
};

#endif // EYELIDSCONTROL_H
