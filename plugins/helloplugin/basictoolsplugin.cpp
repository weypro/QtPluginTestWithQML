#include "basictoolsplugin.h"
#include <QGuiApplication>
#include <QPluginLoader>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

static void qmlRegisterTypeForMyPlugin() {
    qmlRegisterType<HelloPluginViewController>("cn.pluginhello.view", 1, 0, "HelloPluginViewController");
}
[[maybe_unused]] static int registration = (qmlRegisterTypeForMyPlugin(), 0);

void BasicToolsModule::setName(const QString &name) {
    qInfo() << "c++:name:" << name;
    IPluginModuleBase::setName(name);
}

QStringList BasicToolsPlugin::brushes() const {
    return {tr("Pencil"), tr("Air Brush"), tr("Random Letters")};
}

QRect BasicToolsPlugin::createRect(int w) const {
    return QRect{1, 2, 1 + w, 2 + w};
}

void BasicToolsPlugin::initWindowEngine(QQmlApplicationEngine *engine) {
    _engine = engine;
}

void BasicToolsPlugin::showWindow() const {
    _engine->rootContext()->setContextProperty("BasicToolsPlugin", QVariant::fromValue(this));
    _engine->load(QUrl(QLatin1String("qrc:/helloplugin/main.qml")));
}

IPluginModuleBase *BasicToolsPlugin::getModule() const {
    return _module;
}

bool BasicToolsPlugin::setCurrentModuleName(const QString &name) {
    _module->setName(name);
    return true;
}

void BasicToolsPlugin::initIMyAppInterface(IMyAppInterface *interface) {
    _appInterface = interface;
}

void BasicToolsPlugin::processNewMsg(const QString &msg) {
    if(_appInterface!= nullptr){
        _appInterface->sendToConsole(msg + " plugin ");
    }
}
