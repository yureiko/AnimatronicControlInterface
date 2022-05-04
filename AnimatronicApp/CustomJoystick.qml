import QtQuick 2.5
import QtQuick.Window 2.2
import controllers 1.0

Rectangle {

    property var controller
    property int size: 50
    property string backgroundColor: "white"
    property string borderColor: "black"
    property int xPos: 0
    property int yPos: 0
    property real cursorGain: 2.0
    property string cursorImage

    id: joystickBackground
    x: xPos
    y: yPos
    width: size
    height: width
    border.width: 1
    radius: width*0.5
    color: backgroundColor
    border.color: borderColor

    MouseArea{
       id: mouseArea
       hoverEnabled: false
       anchors.fill: joystickBackground
       onPositionChanged: joystickPositionChanged()
    }

    Rectangle {
        id: joystickCenter
        width: parent.width/2
        height: width
        x: (cursorGain*1 + controller.ui_joystickPosition.x) * size/(2*cursorGain) - width/2
        y: (cursorGain*1 - controller.ui_joystickPosition.y) * size/(2*cursorGain) - width/2
        color: "black"
        border.color: borderColor
        border.width: 1
        radius: width*0.5

        Image {
            id: name
            anchors.fill: parent
            source: cursorImage
        }
    }

    function joystickPositionChanged()
    {
        var position = [((2 * mouseArea.mouseX)/size - 1), -((2 * mouseArea.mouseY)/size - 1)]

        controller.setJoystickPosition(position)
    }
}



