#ifndef PLUGINVIEWCONTROLLER_H
#define PLUGINVIEWCONTROLLER_H

#include <QObject>

#include <myapp/helloplugininterface.h>
// 因为插件接口不包含具体ipluginmodulebase的定义，如果在此处不引用其头文件，会无法生成被qml识别的ipluginmodulebase类型
#include <modulecore/include/modulecore/ipluginmodulebase.h>

// 提供一个让界面能调用模块类的控制器
class PluginViewController : public QObject
{
    Q_OBJECT
public:
    explicit PluginViewController(QObject *parent = nullptr);

    Q_INVOKABLE QString showRectString();
    Q_INVOKABLE void showWindow();

    Q_INVOKABLE IPluginModuleBase *getModule();
    Q_INVOKABLE bool setCurrentModuleName(const QString &name);

    Q_INVOKABLE void initIMyAppInterface(IMyAppInterface *interface);
    // 将消息发送到插件
    Q_INVOKABLE void sendMsg(const QString &msg);
};

extern BrushInterface *m_brush;

#endif // PLUGINVIEWCONTROLLER_H
