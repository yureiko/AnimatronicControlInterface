import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import controllers 1.0

Column{
    property var controller
    property int size: 48
    property int fontSize: 0.7 * size
    Row{
        id: emotionsButtons
        spacing: 64 + 1.5 * size

        CheckBox{
            id: emotionNeutralButton

            indicator.width: size
            indicator.height: size
            checked: controller.ui_neutralEmotionChecked
            onClicked: controller.onNeutralEmotionPressed()

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Neutro")
                font.pixelSize: fontSize
            }
        }

        CheckBox{
            id: emotionHappyButton

            indicator.width: size
            indicator.height: size
            checked: controller.ui_happyEmotionChecked
            onClicked: controller.onHappyEmotionPressed()

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Feliz")
                font.pixelSize: fontSize
            }
        }

        CheckBox{
            id: emotionScaredButton

            indicator.width: size
            indicator.height: size
            checked: controller.ui_scaredEmotionChecked
            onClicked: controller.onScaredEmotionPressed()

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Assustado")
                font.pixelSize: fontSize
            }
        }
    }

    Row{
        id: emotionsButtons2
        spacing: 64 + 1.5 * size

        CheckBox{
            id: emotionAngryButton

            indicator.width: size
            indicator.height: size
            checked: controller.ui_angryEmotionChecked
            onClicked: controller.onAngryEmotionPressed()

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Bravo")
                font.pixelSize: fontSize
            }
        }

        CheckBox{
            id: emotionSleepyButton

            indicator.width: size
            indicator.height: size
            checked: controller.ui_sleepyEmotionChecked
            onClicked: controller.onSleepyEmotionPressed()

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Sonolento")
                font.pixelSize: fontSize
            }
        }

        CheckBox{
            id: emotionSuspiciousButton

            indicator.width: size
            indicator.height: size
            checked: controller.ui_suspiciousEmotionChecked
            onClicked: controller.onSuspiciousEmotionPressed()

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Desconfiado")
                font.pixelSize: fontSize
            }
        }
    }
}
