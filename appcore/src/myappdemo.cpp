#include <appcore/myappdemo.h>

MyAppDemo::MyAppDemo(QObject *parent)
    : QObject{parent} {}

QString MyAppDemo::name() const {
    return m_name;
}

void MyAppDemo::setName(const QString &name) {
    if (name == m_name)
        return;

    qInfo() << "c++:name(base):" << name;
    m_name = name;
    emit nameChanged(name);
}
void MyAppDemo::sendToConsole(const QString &msg) {
    qInfo() << "appcorec++" << msg;

    emit consoleMsgChanged(msg + " appcore ");
}
