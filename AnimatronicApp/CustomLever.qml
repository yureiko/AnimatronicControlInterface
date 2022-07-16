import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import controllers 1.0

Rectangle {

    property var controller
    property var rotationPoint
    property bool antiClockWiseRotation: false

    id: customLever
    transformOrigin: rotationPoint
    rotation: antiClockWiseRotation? -controller.ui_rotation : controller.ui_rotation
    color: "black"

    antialiasing: true

    MouseArea{
       id: mouseArea
       hoverEnabled: false
       anchors.fill: customLever
       onPositionChanged: leverPositionChanged()
    }

    function leverPositionChanged()
    {
        var position = [((2 * mouseArea.mouseX)/mouseArea.width - 1), -((2 * mouseArea.mouseY)/mouseArea.height - 1)]

        controller.setRotation(position)
    }
}


