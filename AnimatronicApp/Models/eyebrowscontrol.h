#ifndef EYEBROWSCONTROL_H
#define EYEBROWSCONTROL_H

#include <QObject>

/**
 * @brief The EyebrowsControl class manage the animatronic eyebrows part
 */
class EyebrowsControl : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief Constructor
     * @param parent
     */
    explicit EyebrowsControl(QObject *parent = nullptr);

    /**
     * @brief returns the left eyebrow rotation in degrees
     * @return qreal
     */
    qreal leftRotationDegrees() const;

    /**
     * @brief returns the right eyebrow rotation in degrees
     * @return qreal
     */
    qreal rightRotationDegrees() const;

    /**
     * @brief returns the rotation of both eyebrows in degrees
     * @return QPair<float, float>
     */
    QPair<float, float> positionDegrees();

public slots:

    /**
     * @brief Sets left eyebrow rotation
     * @param rotation
     */
    void setLeftRotationDegrees(qreal rotation);

    /**
     * @brief Sets right eyebrow rotation
     * @param rotation
     */
    void setRightRotationDegrees(qreal rotation);

signals:
    /**
     * @brief notifies qhen rotation degrees changed
     * @param rotation
     */
    void rotationDegreesChanged(qreal rotation);

private:
    qreal m_leftRotationDegrees;
    qreal m_rightRotationDegrees;

};

#endif // EYEBROWSCONTROL_H
