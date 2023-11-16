#include <myapp/helloplugininterface.h>

#include <QDir>
#include <QGuiApplication>
#include <QPluginLoader>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "appcore/include/appcore/myappdemo.h"
#include "pluginviewcontroller.h"

QStringList pluginFileNames;

QQmlApplicationEngine *globalengine;

void populateMenus(QObject *plugin) {
    auto iBrush = qobject_cast<BrushInterface *>(plugin);
    if (iBrush) {
        qInfo() << "plugin ok";

        m_brush = qobject_cast<BrushInterface *>(plugin);
        m_brush->initWindowEngine(globalengine);
    }
}

void loadPlugins() {
    const auto staticInstances = QPluginLoader::staticInstances();
    for (QObject *plugin : staticInstances)
        populateMenus(plugin);
    //! [4] //! [5]

    auto pluginsDir = QDir(QCoreApplication::applicationDirPath());
#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
//    pluginsDir.cd("plugins");
//
//    if (!pluginsDir.cd("helloplugin")) {
//        qWarning() << "no helloplugin";
//    }

    const auto entryList = pluginsDir.entryList(QDir::Files);
    for (const QString &fileName : entryList) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin) {
            populateMenus(plugin);
            pluginFileNames += fileName;
        }
    }
}

int main(int argc, char *argv[]) {
    QQuickWindow::setDefaultAlphaBuffer(true);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<PluginViewController>("cn.pluginhellotest.myview", 1, 0, "PluginViewController");
    qmlRegisterType<MyAppDemo>("cn.pluginhellotest.myview", 1, 0, "MyAppDemo");

    //运行时要设置路径，cmake本身也要设置
    //如果qml插件的cmake写了set(QT_QML_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})就可以不用
    engine.addImportPath(QString("%1/qmlplugins").arg(QCoreApplication::applicationDirPath()));

    const QUrl url(u"qrc:/pluginhellotest/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    globalengine = &engine;

    loadPlugins();

    app.exec();

    delete m_brush;

    return 0;
}
