#ifndef USERQMLPLUGIN_H
#define USERQMLPLUGIN_H

#include <QtQuick/QQuickPaintedItem>

class UserQMLCppPaintedItem : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_DISABLE_COPY(UserQMLCppPaintedItem)
public:
    explicit UserQMLCppPaintedItem(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~UserQMLCppPaintedItem() override;
};

//#include <QQmlEngineExtensionPlugin>

//class UserQMLPlugin : public QQmlEngineExtensionPlugin
//{
//    Q_OBJECT
//    Q_PLUGIN_METADATA(IID "org.user.UserQMLPlugin")
//};

#endif // USERQMLPLUGIN_H
