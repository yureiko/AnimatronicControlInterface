#ifndef LEVERCONTROLLER_H
#define LEVERCONTROLLER_H

#include <QObject>
#include <QVariantList>

class LeverController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal ui_rotation READ rotation NOTIFY rotationChanged)

public:
    explicit LeverController(QObject *parent = nullptr);

    qreal rotation() const;

public slots:
    void setRotation(QVariantList newPosition);

signals:

    void rotationChanged();

private:
    qreal m_rotation;

};

#endif // LEVERCONTROLLER_H
