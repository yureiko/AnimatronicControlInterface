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
        }
        width: 120

        model: toolbarController.ui_availablePortsList
    }

    Button{
        id: serialPortOpenButton
        anchors{
            left: serialPortSelect.right
            leftMargin: 10
        }
        text: toolbarController.ui_serialPortOpenButtonText

        onClicked: toolbarController.onOpenSerialPortPressed(serialPortSelect.currentIndex)
    }

    CheckBox{
        id: btEnabled
        enabled: toolbarController.ui_btConnectionCheckBoxEnabled

        anchors{
            left: serialPortOpenButton.right
        }

        text: qsTr("Conexão bluetooth")

        onClicked: toolbarController.onBTEnabledPressed(checked);
    }
}
