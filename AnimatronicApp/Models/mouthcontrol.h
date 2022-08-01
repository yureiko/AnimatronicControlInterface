#ifndef MOUTHCONTROL_H
#define MOUTHCONTROL_H

#include <QObject>

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
    float m_positionDegrees;

};

#endif // MOUTHCONTROL_H
