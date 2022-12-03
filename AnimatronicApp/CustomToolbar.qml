import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.15

import controllers 1.0

Rectangle {
    id: toolbarBackground
    anchors{
        left: parent.left
        right: parent.right
        top: parent.top
    }
    height: 40

    color: "light gray"

    ComboBox{
        id: serialPortSelect
        visible:  true
        anchors{
            leftMargin: 5
            left: parent.left
            top: parent.top
            bottom: parent.bottom
        }
        width: height * 3

        model: toolbarController.ui_availablePortsList
    }

    Button{
        id: serialPortOpenButton
        anchors{
            top: parent.top
            left: serialPortSelect.right
            leftMargin: height/30
            bottom: parent.bottom
        }
        text: toolbarController.ui_serialPortOpenButtonText

        onClicked: toolbarController.onOpenSerialPortPressed(serialPortSelect.currentIndex)
    }

    CheckBox{
        id: btEnabled

        indicator.width: parent.height * 0.7
        indicator.height: parent.height * 0.7

        enabled: toolbarController.ui_btConnectionCheckBoxEnabled

        anchors{
            left: serialPortOpenButton.right
            verticalCenter: parent.verticalCenter
        }

        text: qsTr("Conexão bluetooth")
        checked: true

        onClicked: toolbarController.onBTEnabledPressed(checked);
    }
}
