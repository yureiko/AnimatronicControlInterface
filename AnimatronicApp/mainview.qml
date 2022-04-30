import QtQuick 2.5
import QtQuick.Window 2.2
import controllers 1.0

Window {
    id: window
    visible: true
    width: 480
    height: 320

    Rectangle {
        id: background
        anchors.fill: parent
        border.color: "white"
        border.width: 1
        color: "gray"

        CustomToolbar {
            id: toolbar
        }

        CustomJoystick {
            id: eyeJoystickLeft
            controller: joystickController
            backgroundColor: "white"
            xPos: 40
            yPos: 80
            size: parent.width/5
            cursorImage: "qrc:/Resources/iris.png"
        }

        CustomJoystick {
            id: eyeJoystickRight
            controller: joystickController
            backgroundColor: "white"
            xPos: 40 + eyeJoystickLeft.size + 20
            yPos: eyeJoystickLeft.yPos
            size: eyeJoystickLeft.size
            cursorImage: "qrc:/Resources/iris.png"
        }
    }
}
