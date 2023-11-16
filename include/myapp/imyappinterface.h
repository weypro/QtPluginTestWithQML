#ifndef IMYAPPINTERFACE_H
#define IMYAPPINTERFACE_H

#include <QObject>
#include <QQmlEngine>

// 应用控制接口
class IMyAppInterface
{
public:
    virtual ~IMyAppInterface() = default;

    // 示例，为其他插件提供发送到控制台（主窗口中的控件）的功能
    virtual void sendToConsole(const QString &msg) = 0;
};

#endif
