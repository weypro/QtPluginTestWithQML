#include "hellopluginviewcontroller.h"
#include <basictoolsplugin.h>

HelloPluginViewController::HelloPluginViewController(QObject *parent)
    : QObject{parent}
{

}

void HelloPluginViewController::initToolsPlugin(BasicToolsPlugin *plugin) {
    _toolsPlugin = plugin;
}

void HelloPluginViewController::sendMsg(const QString &msg) {
    qDebug() << "hellocl: " << msg;
    _toolsPlugin->processNewMsg(msg + " hellocl ");
}
