import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import controllers 1.0
import QtGraphicalEffects 1.15

Window {
    property real proportion: 4/3

    id: window
    visible: true
    width: 480
    height: proportion*width

    minimumHeight: height
    minimumWidth: width
    maximumHeight: height
    maximumWidth: width

    Rectangle {
        id: background
        anchors.fill: parent
        border.color: "white"
        border.width: 1
        color: "orange"

        CustomToolbar {
            id: toolbar
        }

        CustomJoystick {
            id: eyeJoystickLeft
            controller: eyesController
            backgroundColor: "white"
            anchors{
                top: toolbar.bottom
                topMargin: 80
                left: background.left
                leftMargin: 70

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
            value: 0.5

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
            id: centerEyesReference
            anchors{
                right: eyeJoystickRight.left
                left: eyeJoystickLeft.right
                top: eyeJoystickLeft.bottom
            }
            height: width
            color: "transparent"
        }

        Rectangle
        {
            id: snout
            width: eyeJoystickRight.size * 1.2
            height: width *0.65
            color: "transparent"

            anchors{
                horizontalCenter: centerEyesReference.horizontalCenter
                verticalCenter: centerEyesReference.verticalCenter
            }

            Image {
                id: snoutImage
                anchors.fill: parent
                source: "qrc:/Resources/snout.svg"
            }
        }

        Rectangle{
            id: mouth
            width: snout.width*0.65
            height: width *0.5
            color: "transparent"

            anchors{
                horizontalCenter: snout.horizontalCenter

            }
            y: (1 - mouthSlider.position) * 0.5 * height + snout.y + snout.height

            Image {
                id: mouthImage
                anchors.fill: parent
                source: "qrc:/Resources/mouth.svg"
            }
        }

        Slider {
            id: mouthSlider
            orientation: Qt.Vertical
            value: 1.0

            height: eyelidsSlider.height

            anchors{
                top: snout.bottom
                left: eyeJoystickRight.right
                leftMargin: eyeJoystickRight.size/8
            }
            stepSize: 0.01
            onMoved: mouthController.onPositionChanged(position)
        }
    }
}
