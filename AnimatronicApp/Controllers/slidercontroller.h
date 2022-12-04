/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

#ifndef SLIDERCONTROLLER_H
#define SLIDERCONTROLLER_H

#include <QObject>

/**
 * @brief The SliderController class provides a controller for a slider view
 */
class SliderController : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param parent
     */
    explicit SliderController(QObject *parent = nullptr);

    /**
     * @brief returns the normalized slider position
     * @return
     */
    float sliderPosition() const;

signals:
    /**
     * @brief notifies the view when slider position changed
     */
    void sliderPositionChanged();

public slots:
    /**
     * @brief internal slot triggered when slider view position changed
     * @param position
     */
    Q_INVOKABLE void onPositionChanged(float position);

private:
    float m_sliderPosition;
};

#endif // SLIDERCONTROLLER_H
