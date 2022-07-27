#ifndef EYEBROWSCONTROL_H
#define EYEBROWSCONTROL_H

#include <QObject>

class EyebrowsControl : public QObject
{
    Q_OBJECT
public:
    explicit EyebrowsControl(QObject *parent = nullptr);

    qreal leftRotationDegrees() const;

    qreal rightRotationDegrees() const;

public slots:
    void setLeftRotationDegrees(qreal rotation);

    void setRightRotationDegrees(qreal rotation);

signals:
    void rotationDegreesChanged(qreal rotation);

private:
    qreal m_leftRotationDegrees;
    qreal m_rightRotationDegrees;

};

#endif // EYEBROWSCONTROL_H
