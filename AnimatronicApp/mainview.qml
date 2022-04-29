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
            id: joystick
            backgroundColor: "orange"
            xPos: 40
            yPos: 80
            size: parent.width/5
        }
    }
}
