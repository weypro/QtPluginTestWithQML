#ifndef HELLOPLUGINVIEWCONTROLLER_H
#define HELLOPLUGINVIEWCONTROLLER_H

#include <QObject>

class BasicToolsPlugin;

class HelloPluginViewController : public QObject
{
    Q_OBJECT
public:
    explicit HelloPluginViewController(QObject *parent = nullptr);

    Q_INVOKABLE void initToolsPlugin(BasicToolsPlugin *plugin);
    Q_INVOKABLE void sendMsg(const QString &msg);

private:
    BasicToolsPlugin *_toolsPlugin;
};

#endif // HELLOPLUGINVIEWCONTROLLER_H
