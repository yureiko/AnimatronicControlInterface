/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#ifndef LEVERCONTROLLER_H
#define LEVERCONTROLLER_H

#include <QObject>
#include <QVariantList>

/**
 * @brief The LeverController class provides a controller for a lever view
 */
class LeverController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal ui_rotation READ rotation NOTIFY rotationChanged)

public:
    /**
     * @brief Constructor
     * @param parent
     */
    explicit LeverController(QObject *parent = nullptr);

    /**
     * @brief returns the rotation
     * @return
     */
    qreal rotation() const;

public slots:

    /**
     * @brief set rotation
     * @param newPosition
     */
    void setRotation(QVariantList newPosition);

signals:

    /**
     * @brief notifies the view when rotation changed
     */
    void rotationChanged();

private:
    qreal m_rotation;

};

#endif // LEVERCONTROLLER_H
