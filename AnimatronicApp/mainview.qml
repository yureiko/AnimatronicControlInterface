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

Window {
    property real proportion: 21/9

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

        /****** TOOL BAR ********************************************/
        CustomToolbar {
            id: toolbar
            height: parent.width /10
        }

        /****** TITLE: *********************************************/

        Text{
            anchors.top: toolbar.bottom
            anchors.topMargin: parent.width/10
            anchors.horizontalCenter: centerEyesReference.horizontalCenter
            text: qsTr("NICK")
            color: "white"
            font.pixelSize: background.width / 10
            font.bold: true
        }

        /****** EYES: ***********************************************/
        CustomJoystick {
            id: eyeJoystickLeft
            controller: eyesController
            backgroundColor: "white"
            anchors{
                top: toolbar.bottom
                topMargin: parent.width/2
                left: background.left
                leftMargin: 40

            }

            size: parent.width * 0.27
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

        /****** EYELIDS: ********************************************/
        Slider {
            id: superiorEyelidsSlider
            orientation: Qt.Vertical
            value: eyelidsSlider.position

            anchors{
                topMargin: - eyeJoystickRight.size/8
                top: eyeJoystickRight.top
                bottom: eyeJoystickRight.verticalCenter
                left: eyeJoystickRight.right
                leftMargin: eyeJoystickRight.size/7
            }
            stepSize: 0.01
            onMoved: superiorEyelidsController.onPositionChanged(position)
        }

        Slider {
            id: inferiorEyelidsSlider
            orientation: Qt.Vertical
            rotation: 180
            value: eyelidsSlider.position

            anchors{
                top: superiorEyelidsSlider.bottom
                left: eyeJoystickRight.right
                leftMargin: eyeJoystickRight.size/7
            }
            height: superiorEyelidsSlider.height
            stepSize: 0.01
            onMoved: inferiorEyelidsController.onPositionChanged(position)
        }

        Slider {
            id: eyelidsSlider
            orientation: Qt.Vertical
            value: 0.5

            anchors{
                top: superiorEyelidsSlider.top
                bottom: inferiorEyelidsSlider.bottom
                left: superiorEyelidsSlider.right
                leftMargin: parent.width * 0.05
            }
            stepSize: 0.01
            onMoved: {
                superiorEyelidsController.onPositionChanged(position);
                inferiorEyelidsController.onPositionChanged(position);
            }
        }

        Text {
            id: eyelidsDescription
            text: qsTr("Pálpebras")
            font.pixelSize: 0.7 * background.width / 18

            anchors{
                bottom: superiorEyelidsSlider.top
                left: superiorEyelidsSlider.left
                leftMargin: 10
            }
        }

        /****** EYEBROWS: *******************************************/
        CustomLever {
            id: eyeBrowLeft
            anchors{
                left: eyeJoystickLeft.left
                bottom: eyeJoystickLeft.top

            }

            controller: leftEyebrowController
            rotationPoint: Item.Left
            image: "qrc:/Resources/eyebrow.png"
            mirrored: false
            height: eyeJoystickLeft.size/2.5
            width: eyeJoystickLeft.width
        }

        CustomLever {
            id: eyeBrowRight
            anchors{
                right: eyeJoystickRight.right
                bottom: eyeJoystickRight.top
            }

            controller: rightEyebrowController
            rotationPoint: Item.Right
            antiClockWiseRotation: true
            image: "qrc:/Resources/eyebrow.png"
            mirrored: true
            height: eyeJoystickRight.size/2.5
            width: eyeJoystickLeft.width
        }

        /****** SNOUT ALIGMENT: *************************************/
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
                source: "qrc:/Resources/snout.png"
            }
        }

        /****** MOUTH: **********************************************/
        Rectangle{
            id: mouth
            width: snout.width*0.65
            height: width *0.5
            color: "transparent"

            anchors{
                horizontalCenter: snout.horizontalCenter

            }
            y: (mouthSlider.position) * 0.5 * height + snout.y + snout.height

            Image {
                id: mouthImage
                anchors.fill: parent
                source: "qrc:/Resources/mouth.png"
            }
        }

        Slider {
            id: mouthSlider
            orientation: Qt.Vertical
            rotation: 180
            value: 0.0

            height: inferiorEyelidsSlider.height * 1.3

            anchors{
                top: snout.bottom
                topMargin: -eyeJoystickRight.size/4
                left: eyeJoystickRight.right
                leftMargin: -eyeJoystickRight.size/8
            }
            stepSize: 0.01
            onMoved: mouthController.onPositionChanged(1.0 - position)
        }

        Text {
            id: mouthDescription
            text: qsTr("Boca")
            font.pixelSize:  0.7 * background.width / 18
            anchors{
                bottom: mouthSlider.top
                horizontalCenter: mouthSlider.horizontalCenter
            }
        }

        /****** EYELIDS ANIMATION: **********************************/
        Image{
            id: leftSuperiorEyelidAnimation
            source: "qrc:/Resources/eyelidClosed100.png"
            anchors{
                top: eyeJoystickLeft.top
                horizontalCenter: eyeJoystickLeft.horizontalCenter
            }
            height: (1 - superiorEyelidsSlider.value * 0.6) * eyeJoystickLeft.size/2
            width: eyeJoystickLeft.width - superiorEyelidsSlider.value * eyeJoystickLeft.size/6
        }
        Image{
            id: rightSuperiorEyelidAnimation
            source: "qrc:/Resources/eyelidClosed100.png"
            anchors{
                top: eyeJoystickRight.top
                horizontalCenter: eyeJoystickRight.horizontalCenter
            }
            height: (1 - superiorEyelidsSlider.value * 0.6) * eyeJoystickLeft.size/2
            width: eyeJoystickRight.width - superiorEyelidsSlider.value * eyeJoystickRight.size/6
        }
        Image{
            id: leftInferiorEyelidAnimation
            source: "qrc:/Resources/eyelidClosed100.png"
            anchors{
                bottom: eyeJoystickLeft.bottom
                horizontalCenter: eyeJoystickLeft.horizontalCenter
            }
            height: (1 - inferiorEyelidsSlider.value * 0.6) * eyeJoystickLeft.size/2
            width: eyeJoystickLeft.width - inferiorEyelidsSlider.value *  eyeJoystickLeft.size/6
            rotation: 180
        }
        Image{
            id: rightInferiorEyelidAnimation
            source: "qrc:/Resources/eyelidClosed100.png"
            anchors{
                bottom: eyeJoystickRight.bottom
                horizontalCenter: eyeJoystickRight.horizontalCenter
            }
            height: (1 - inferiorEyelidsSlider.value * 0.6) * eyeJoystickLeft.size/2
            width: eyeJoystickRight.width - inferiorEyelidsSlider.value * eyeJoystickRight.size/6
            rotation: 180
        }

        /****** EMOTIONS CONTROL: **********************************/

        ButtonGrade {
            size: background.width / 18
            spacing: size * 0.8
            anchors{
                horizontalCenter: snout.horizontalCenter
                top: snout.bottom
                topMargin: background.width/3
            }
            controller: emotionsButtonGradeController
        }
    }
}
