#ifndef EYELIDSCONTROL_H
#define EYELIDSCONTROL_H

#include <QObject>
#include <QTimer>

/**
 * @brief The EyelidsControl class manage the animatronic eyelids part
 */
class EyelidsControl : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param parent
     */
    explicit EyelidsControl(QObject *parent = nullptr);

    /**
     * @brief returns the eyelids position in degrees
     * @return QPair<float,float>
     */
    QPair<float,float> positionDegrees() const;

    /**
     * @brief sets the position center offset in degrees
     * @param yOffset
     */
    void setPositionCenterYOffsetDegrees(float yOffset);

public slots:
    /**
     * @brief sets the eyelids position in degrees
     * @param newPosition
     */
    void setPositionDegrees(QPair<float,float> newPosition);

signals:

    /**
     * @brief notifies when position in degrees changed
     * @param positionDegrees
     */
    void positionDegreesChanged(QPair<float,float> positionDegrees);

private:

    /**
     * @brief Closes and opens eyelids for a short random time
     */
    void blink();

    QPair<float,float> m_positionDegrees;
    QPair<float,float> m_positionCenterOffsetDegrees;

    QTimer *m_blinkTimer;
    QPair<float,float> m_lastPositionDegrees;
    QPair<float,float> m_lastPositionCenterOffsetDegrees;
    bool m_isBlinking;
};

#endif // EYELIDSCONTROL_H
