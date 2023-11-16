#include "pluginviewcontroller.h"
#include <myapp/helloplugininterface.h>
#include <QRect>

BrushInterface *m_brush = nullptr;

PluginViewController::PluginViewController(QObject *parent)
    : QObject{parent} {}

QString PluginViewController::showRectString() {
    if (m_brush != nullptr) {
        auto rect = m_brush->createRect(5);

        return QString::number(rect.right());
    }
    qWarning() << "???";
    return "";
}

void PluginViewController::showWindow() {
    m_brush->showWindow();
}

IPluginModuleBase *PluginViewController::getModule() {
    return m_brush->getModule();
}

bool PluginViewController::setCurrentModuleName(const QString &name) {
    return m_brush->setCurrentModuleName(name);
}

void PluginViewController::initIMyAppInterface(IMyAppInterface *interface) {
    m_brush->initIMyAppInterface(interface);
}
void PluginViewController::sendMsg(const QString &msg) {
    m_brush->processNewMsg(msg + " maincl ");
}
