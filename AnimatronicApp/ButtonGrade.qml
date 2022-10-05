import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import controllers 1.0

Column{
    property var controller
    Row{
        id: emotionsButtons
        spacing: 64

        CheckBox{
            id: emotionNeutralButton
            checked: controller.ui_neutralEmotionChecked
            onClicked: controller.onNeutralEmotionPressed

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Neutro")
            }
        }

        CheckBox{
            id: emotionHappyButton
            checked: controller.ui_happyEmotionChecked
            onClicked: controller.onHappyEmotionPressed

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Feliz")
            }
        }

        CheckBox{
            id: emotionScaredButton
            checked: controller.ui_scaredEmotionChecked
            onClicked: controller.onScaredEmotionPressed

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Assustado")
            }
        }
    }

    Row{
        id: emotionsButtons2
        spacing: 64

        CheckBox{
            id: emotionAngryButton
            checked: controller.ui_angryEmotionChecked
            onClicked: controller.onAngryEmotionPressed

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Bravo")
            }
        }

        CheckBox{
            id: emotionSleepyButton
            checked: controller.ui_sleepyEmotionChecked
            onClicked: controller.onSleepyEmotionPressed

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Sonolento")
            }
        }

        CheckBox{
            id: emotionSuspiciousButton
            checked: controller.ui_suspiciousEmotionChecked
            onClicked: controller.onSuspiciousEmotionPressed

            Text{
                anchors.left: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Desconfiado")
            }
        }
    }
}
