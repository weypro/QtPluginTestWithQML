import QtQuick
import QtQuick.Controls
import "."

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 320
    height: 240
    title: qsTr("插件hello纯窗口")

    QtStyleButton {

        onClicked: {
            console.log("purewindow clicked")
        }
    }
}
