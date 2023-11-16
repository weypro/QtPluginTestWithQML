import QtQuick
import QtQuick.Controls
import cn.pluginhello.view

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 320
    height: 240
    title: qsTr("插件hello")

    HelloPluginViewController {
        id: helloPluginViewController

        Component.onCompleted: {
            initToolsPlugin(BasicToolsPlugin)
        }
    }

    Button {
        id: button
        text: qsTr("插件中的按钮")
        height: 48
        width: 120
        anchors.centerIn: parent
        onClicked: {
            console.debug(qsTr("点击了插件中的按钮"))

            //无法跨窗口
            //            textInput.text = "123"

            // 写法1
            // BasicToolsPlugin.processNewMsg(text)
            // 写法2
            helloPluginViewController.sendMsg(text)
        }
    }
}
