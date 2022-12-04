/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#ifndef MOUTHCONTROL_H
#define MOUTHCONTROL_H

#include <QObject>
#include <QTimer>

/**
 * @brief The MouthControl class manages the animatronic mouth part
 */
class MouthControl : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param parent
     */
    explicit MouthControl(QObject *parent = nullptr);

    /**
     * @brief return the mouth position in degrees
     * @return float
     */
    float positionDegrees() const;

public slots:
    /**
     * @brief set mouth position in degrees
     * @param newPosition
     */
    void setPositionDegrees(float newPosition);

signals:
    /**
     * @brief notifies when mouth position in degrees changed
     * @param positionDegrees
     */
    void positionDegreesChanged(float positionDegrees);

private:
    /**
     * @brief slightly opens and closes mouth part
     */
    void breathe();

    float m_positionDegrees;
    QTimer *m_breatheTimer;
    float m_breatheOffsetDegrees;
    bool m_isBreathOffsetIncrement;
};

#endif // MOUTHCONTROL_H
