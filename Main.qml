import QtQuick
import QtQuick.Window
import cn.pluginhellotest.myview
import QtQuick.Controls
import QtQuick.Layouts
import Charts
import UserQMLPlugin

Window {
    width: 640
    height: 700
    visible: true
    title: qsTr("插件测试")

    PluginViewController {
        id: pluginViewController
    }
    MyAppDemo {
        id: appInterface
    }

    Connections {
        target: appInterface
        function onConsoleMsgChanged(msg) {
            consoleMsgControl.text = msg
        }
    }

    ScrollView {
        anchors.fill: parent
        //        width: parent.width
        contentWidth: parent.width
        clip: true

        ColumnLayout {
            spacing: 6
            anchors.fill: parent

            ColumnLayout {
                spacing: 6
                Layout.fillWidth: true
                Layout.leftMargin: 50
                Layout.rightMargin: 50

                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    text: "普通接口"
                    // anchors.centerIn: parent
                    onClicked: {
                        // 调用C++接口并将返回的QString赋值给文本框
                        textInput.text = pluginViewController.showRectString()
                    }
                }

                TextInput {
                    Layout.fillWidth: true
                    id: textInput
                    text: "test"
                    anchors.margins: 10
                    readOnly: true
                    font.pixelSize: 20
                }
            }

            Rectangle {
                Layout.topMargin: 20
                Layout.fillWidth: true
                height: 1
                color: "#1f1f1f"
            }

            ColumnLayout {
                spacing: 6
                Layout.fillWidth: true
                Layout.leftMargin: 50
                Layout.rightMargin: 50
                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    text: "显示并绑定插件内所生成模块的名称"
                    onClicked: {

                        textInput2.text = Qt.binding(function () {
                            return pluginViewController.getModule().name
                        })
                    }
                }
                Label {
                    Layout.fillWidth: true
                    text: "当前模块名"
                }

                TextInput {
                    Layout.fillWidth: true
                    id: textInput2
                    anchors.margins: 10
                    readOnly: true
                    font.pixelSize: 20

                    //                    signal __labelNoduleName(string name)

                    //                    function labelNoduleName(name) {
                    //                        console.log(name)
                    //                    }

                    //                    Component.onCompleted: {
                    //                        textInput2.__labelNoduleName.connect(labelNoduleName)
                    //                    }
                }

                Label {
                    Layout.fillWidth: true
                    text: "要修改的模块名，回车确认"
                }

                TextField {
                    Layout.fillWidth: true
                    id: textInput3
                    text: "test"
                    anchors.margins: 10
                    font.pixelSize: 20

                    onEditingFinished: {
                        console.log(text)
                        pluginViewController.setCurrentModuleName(text)
                    }
                }
            }

            Rectangle {
                Layout.topMargin: 20
                Layout.fillWidth: true
                height: 1
                color: "#1f1f1f"
            }

            ColumnLayout {
                spacing: 6
                Layout.fillWidth: true
                Layout.leftMargin: 50
                Layout.rightMargin: 50

                Label {
                    Layout.fillWidth: true
                    text: "待发送消息(会实现echo效果，回应消息显示在控制台)"
                }

                TextField {
                    Layout.fillWidth: true
                    id: userMsg
                    anchors.margins: 10
                    font.pixelSize: 20

                    onEditingFinished: {
                        console.log("qmlsendmsg", text)
                        pluginViewController.initIMyAppInterface(
                                    appInterface)
                        pluginViewController.sendMsg(text)
                        //                    pluginViewController.setCurrentModuleName(text)
                    }
                }

                Label {
                    Layout.fillWidth: true
                    text: "控制台消息框"
                }

                TextInput {
                    Layout.fillWidth: true
                    id: consoleMsgControl
                    text: "test"
                    readOnly: true
                    anchors.margins: 10
                    font.pixelSize: 20
                }

                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    text: "显示窗口(engine传入插件调用)"
                    onClicked: {
                        pluginViewController.showWindow()
                    }
                }
            }

            Rectangle {
                Layout.topMargin: 20
                Layout.fillWidth: true
                height: 1
                color: "#1f1f1f"
            }

            ColumnLayout {
                spacing: 6
                Layout.fillWidth: true
                Layout.leftMargin: 50
                Layout.rightMargin: 50

                Label {
                    Layout.fillWidth: true
                    text: "qml插件饼图"
                }

                PieChart {
                    Layout.alignment: Qt.AlignHCenter
                    width: 100
                    height: 100

                    slices: [
                        PieSlice {
                            anchors.fill: parent
                            color: "red"
                            fromAngle: 0
                            angleSpan: 110
                        },
                        PieSlice {
                            anchors.fill: parent
                            color: "black"
                            fromAngle: 110
                            angleSpan: 50
                        },
                        PieSlice {
                            anchors.fill: parent
                            color: "blue"
                            fromAngle: 160
                            angleSpan: 100
                        }
                    ]
                }

                Label {
                    Layout.fillWidth: true
                    text: "qml插件按钮"
                }

                RowLayout {

                    UserQMLCppPaintedItem {
                        width: 30
                        height: 30
                    }

                    UserQMLPluginControls {
                        onClicked: {
                            console.log("userbutton clicked")
                        }
                    }
                }
            }

            ColumnLayout {
                spacing: 6
                Layout.fillWidth: true
                Layout.leftMargin: 50
                Layout.rightMargin: 50

                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    text: "显示窗口(Loader加载qml)"
                    onClicked: {
                        qmlloader.reset()
                        qmlloader.source = "qrc:/helloplugin/purewindow.qml"
                    }
                }

                Button {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    text: "显示插件内按钮(Loader加载qml)"
                    onClicked: {
                        qmlloader.reset()
                        qmlloader.source = "qrc:/helloplugin/QtStyleButton.qml"
                    }
                }

                Loader {
                    id: qmlloader

                    //                    Component.onDestruction: source = undefined
                    function reset() {
                        console.log('reset')
                        source = ""
                    }
                }
            }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }
}
