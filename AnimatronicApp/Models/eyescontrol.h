/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#ifndef EYESCONTROL_H
#define EYESCONTROL_H

#include <QObject>
#include <QPointF>

/**
 * @brief The EyesControl class manages the animatronic eyes part
 */
class EyesControl : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param parent
     */
    explicit EyesControl(QObject *parent = nullptr);

    /**
     * @brief returns the eyes position in degrees
     * @return QPointF
     */
    QPointF positionDegrees() const;

public slots:
    /**
     * @brief sets the eyes position in degrees
     * @param newPosition
     */
    void setPositionDegrees(QPointF newPosition);

signals:
    /**
     * @brief notifies when eyes position in degrees changed
     * @param positionDegrees
     */
    void positionDegreesChanged(QPointF positionDegrees);

private:
    QPointF m_positionDegrees;
};

#endif // EYESCONTROL_H
