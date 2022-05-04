import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
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
            anchors{
                top: toolbar.bottom
                topMargin: 40
                left: background.left
                leftMargin: 40

            }

            size: parent.width/5
            cursorImage: "qrc:/Resources/iris.png"
        }

        CustomJoystick {
            id: eyeJoystickRight
            controller: joystickController
            backgroundColor: "white"

            anchors{
                top: eyeJoystickLeft.top
                left: eyeJoystickLeft.right
                leftMargin: size/4
            }

            size: eyeJoystickLeft.size
            cursorImage: "qrc:/Resources/iris.png"
        }

        Slider {
            id: eyelidsSlider
            orientation: Qt.Vertical

            anchors{
                top: eyeJoystickRight.top
                bottom: eyeJoystickRight.bottom
                left: eyeJoystickRight.right
                leftMargin: eyeJoystickRight.size/8
            }
            stepSize: 0.01
            onMoved: sliderController.onPositionChanged(position)
        }
    }
}
