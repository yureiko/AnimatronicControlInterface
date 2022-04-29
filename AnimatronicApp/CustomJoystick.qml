import QtQuick 2.5
import QtQuick.Window 2.2
import controllers 1.0

Item{
    id: customJoystick

    property int size: 50
    property string backgroundColor: "orange"
    property int xPos: 0
    property int yPos: 0

    Rectangle {
        id: joystickBackground
        x: xPos
        y: yPos
        width: size
        height: width
        border.width: 1
        radius: width*0.5
        color: backgroundColor
        border.color: "white"

        Rectangle {
            id: joystickCenter
            width: parent.width/3
            height: width
            x: (1 + joystickController.ui_joystickPosition.x) * size/2 - width/2
            y: (1 - joystickController.ui_joystickPosition.y) * size/2 - width/2
            color: "black"
            border.color: "white"
            border.width: 1
            radius: width*0.5
        }

        MouseArea{
           id: mouseArea
           hoverEnabled: false
           anchors.fill: joystickBackground
           onPositionChanged: joystickPositionChanged()
        }
    }

    function joystickPositionChanged()
    {
        var position = [((2 * mouseArea.mouseX)/size - 1), -((2 * mouseArea.mouseY)/size - 1)]

        joystickController.setJoystickPosition(position)
    }
}
