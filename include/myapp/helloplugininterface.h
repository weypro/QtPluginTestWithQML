#ifndef HELLOPLUGININTERFACE_H
#define HELLOPLUGININTERFACE_H

#include <QtPlugin>
#include "imyappinterface.h"

QT_BEGIN_NAMESPACE
class QPainter;
class QRect;
class QString;
class QQmlApplicationEngine;
QT_END_NAMESPACE

class IPluginModuleBase;

// 插件接口
class BrushInterface
{
public:
    virtual ~BrushInterface() = default;

    virtual QStringList brushes() const = 0;
    virtual QRect createRect(int w) const = 0;

    virtual void initWindowEngine(QQmlApplicationEngine *engine) = 0;
    virtual void showWindow() const = 0;

    virtual IPluginModuleBase *getModule() const = 0;
    virtual bool setCurrentModuleName(const QString &name) = 0;

    virtual void initIMyAppInterface(IMyAppInterface *interface) = 0;
    virtual void processNewMsg(const QString &msg) = 0;
};

QT_BEGIN_NAMESPACE

#define BrushInterface_iid "org.plugintest.BrushInterface/1.0"

Q_DECLARE_INTERFACE(BrushInterface, BrushInterface_iid)

QT_END_NAMESPACE

#endif //HELLOPLUGININTERFACE_H
