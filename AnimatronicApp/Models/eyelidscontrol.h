#ifndef EYELIDSCONTROL_H
#define EYELIDSCONTROL_H

#include <QObject>

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
    QPair<float,float> m_positionDegrees;
    QPair<float,float> m_positionCenterOffsetDegrees;

signals:

};

#endif // EYELIDSCONTROL_H
