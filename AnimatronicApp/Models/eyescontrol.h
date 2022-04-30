#ifndef EYESCONTROL_H
#define EYESCONTROL_H

#include <QObject>
#include <QPointF>

class EyesControl : public QObject
{
    Q_OBJECT
public:
    explicit EyesControl(QObject *parent = nullptr);

    QPointF positionDegrees() const;

public slots:
    void setPositionDegrees(QPointF newPosition);

signals:
    void positionDegreesChanged(QPointF posiitonDegrees);

private:
    QPointF m_positionDegrees;
};

#endif // EYESCONTROL_H
