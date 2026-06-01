import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import HistoryMerge

ApplicationWindow {
    id: window
    width: 420
    height: 760
    visible: true
    title: "History Merge"

    Rectangle {
        anchors.fill: parent
        color: "#202124"

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 12
            spacing: 12

            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 70
                radius: 16
                color: "#303134"

                Text {
                    anchors.centerIn: parent
                    text: "History Merge - Taş Devri"
                    color: "white"
                    font.pixelSize: 22
                    font.bold: true
                }
            }

            GridView {
                id: boardView

                Layout.fillWidth: true
                Layout.fillHeight: true

                model: gameBoardModel

                cellWidth: width / gameBoardModel.columns()
                cellHeight: cellWidth

                interactive: false
                clip: true

                delegate: Rectangle {
                    width: boardView.cellWidth - 6
                    height: boardView.cellHeight - 6
                    radius: 12
                    color: itemLevel > 0 ? "#8d6e63" : "#3c4043"
                    border.color: "#5f6368"
                    border.width: 1

                    Text {
                        anchors.centerIn: parent
                        width: parent.width - 8
                        text: itemName
                        color: "white"
                        font.pixelSize: 11
                        horizontalAlignment: Text.AlignHCenter
                        wrapMode: Text.WordWrap
                    }
                }
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 64
                radius: 16
                color: "#303134"

                Text {
                    anchors.centerIn: parent
                    text: "Alt Menü: Görevler | Çağlar | Market"
                    color: "#e8eaed"
                    font.pixelSize: 15
                }
            }
        }
    }
}