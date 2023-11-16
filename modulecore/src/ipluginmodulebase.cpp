#include <modulecore/ipluginmodulebase.h>

IPluginModuleBase::IPluginModuleBase(QObject *parent)
    : QObject{parent} {}

QString IPluginModuleBase::name() const {
    return m_name;
}

void IPluginModuleBase::setName(const QString &name) {
    if (name == m_name)
        return;

    qInfo() << "c++:name(base):" << name;
    m_name = name;
    emit nameChanged(name);
}
