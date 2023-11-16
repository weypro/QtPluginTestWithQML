#ifndef BASICTOOLSPLUGIN_H
#define BASICTOOLSPLUGIN_H


#include <myapp/helloplugininterface.h>

#include <hellopluginviewcontroller.h>
#include <modulecore/ipluginmodulebase.h>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QRect>
#include <QStringList>
#include <QtPlugin>

class BasicToolsModule : public IPluginModuleBase
{
    Q_OBJECT
public:
    BasicToolsModule() { m_name = "123"; }

    void setName(const QString &name) override;
};

class BasicToolsPlugin : public QObject, BrushInterface, QEnableSharedFromThis<BasicToolsPlugin>
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID BrushInterface_iid FILE "basictools.json")
    Q_INTERFACES(BrushInterface)
public:
    // BrushInterface
    BasicToolsPlugin()
        : _appInterface(nullptr) {
        _module = new BasicToolsModule();

        // 不放在插件类中，就要借助全局变量的特性
        //        qmlRegisterType<HelloPluginViewController>("cn.pluginhello.view", 1, 0, "HelloPluginViewController");
    }
    QStringList brushes() const override;
    QRect createRect(int w) const override;
    void initWindowEngine(QQmlApplicationEngine *engine) override;
    void showWindow() const override;

    IPluginModuleBase *getModule() const override;

    bool setCurrentModuleName(const QString &name) override;

    void initIMyAppInterface(IMyAppInterface *interface) override;

    // 处理消息，演示实现echo效果
    Q_INVOKABLE void processNewMsg(const QString &msg) override;

private:
    QQmlApplicationEngine *_engine;
    BasicToolsModule *_module;

    IMyAppInterface *_appInterface;
};

Q_DECLARE_METATYPE(BasicToolsPlugin)

#endif
