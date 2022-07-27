import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import controllers 1.0

Window {
    id: window
    visible: true
    width: 480
    height: 480

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
            controller: eyesController
            backgroundColor: "white"
            anchors{
                top: toolbar.bottom
                topMargin: 60
                left: background.left
                leftMargin: 60

            }

            size: parent.width/4
            cursorImage: "qrc:/Resources/iris.png"
        }

        CustomJoystick {
            id: eyeJoystickRight
            controller: eyesController
            backgroundColor: "white"

            anchors{
                top: eyeJoystickLeft.top
                left: eyeJoystickLeft.right
                leftMargin: size/2
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
            onMoved: eyelidsController.onPositionChanged(position)
        }

        CustomLever {
            id: eyeBrowLeft
            anchors{
                left: eyeJoystickLeft.left
                bottom: eyeJoystickLeft.top
                bottomMargin: eyeJoystickLeft.size/10
            }

            controller: leftEyebrowController
            rotationPoint: Item.Left
            height: eyeJoystickLeft.size/6
            width: eyeJoystickLeft.width
        }

        CustomLever {
            id: eyeBrowRight
            anchors{
                right: eyeJoystickRight.right
                bottom: eyeJoystickRight.top
                bottomMargin: eyeJoystickRight.size/10
            }

            controller: rightEyebrowController
            rotationPoint: Item.Right
            antiClockWiseRotation: true
            height: eyeJoystickRight.size/6
            width: eyeJoystickLeft.width
        }

        Rectangle {
            id: snout
            anchors{
                right: eyeJoystickRight.left
                left: eyeJoystickLeft.right
                top: eyeJoystickLeft.bottom
                topMargin: -width * 0.25
            }
            height: width * 0.9
            radius: width * 0.3

            color: "black"

        }


    }
}
