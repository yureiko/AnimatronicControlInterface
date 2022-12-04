/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#ifndef JOYSTICKCONTROLLER_H
#define JOYSTICKCONTROLLER_H

#include <QObject>
#include <QPointF>
#include <QVariantList>

/**
 * @brief The JoystickController class provides a controller for a joystick view
 */
class JoystickController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPointF ui_joystickPosition READ joystickPosition NOTIFY joystickPositionChanged)

public:
    /**
     * @brief Constructor
     * @param parent
     */
    explicit JoystickController(QObject *parent = nullptr);

    /**
     * @brief returns the normalized joystick position
     * @return QPointF
     */
    QPointF joystickPosition() const;

public slots:
    /**
     * @brief sets the joystick position
     * @param newJoystickPosition
     */
    void setJoystickPosition(QVariantList newJoystickPosition);

signals:

    /**
     * @brief notifies the view when joystick position changed
     */
    void joystickPositionChanged();

private:
    QPointF m_joystickPosition;

};

#endif // JOYSTICKCONTROLLER_H
