/**
 * This file is part of Animatronic Control project which is released under GPLv3 license.
 * See file LICENSE.txt or go to https://www.gnu.org/licenses/gpl-3.0.txt for full license details.
 *
 * Author: Yuri Andreiko
 * Year: 2022
 */

import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import controllers 1.0

Rectangle {

    property var controller
    property var rotationPoint
    property bool antiClockWiseRotation: false
    property var image
    property bool mirrored

    id: customLever
    transformOrigin: rotationPoint
    rotation: antiClockWiseRotation? -controller.ui_rotation : controller.ui_rotation
    color: "transparent"

    antialiasing: true

    Image {
        anchors.fill: parent
        source: image
        mirror: mirrored
    }

    MouseArea{
       id: mouseArea
       hoverEnabled: false
       anchors.fill: customLever
       onPositionChanged: leverPositionChanged()
    }

    function leverPositionChanged()
    {
        var position = [((2 * mouseArea.mouseX)/mouseArea.width - 1), -((10 * mouseArea.mouseY)/mouseArea.height - 1)]

        controller.setRotation(position)
    }
}


