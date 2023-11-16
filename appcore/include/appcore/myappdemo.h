#ifndef APPCORE_H
#define APPCORE_H

#include <myapp/imyappinterface.h>
#include <QObject>

// 应用内接口实现
class MyAppDemo : public QObject, IMyAppInterface
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

    QML_ELEMENT
public:
    explicit MyAppDemo(QObject *parent = nullptr);

    virtual QString name() const;
    virtual void setName(const QString &name);

    void sendToConsole(const QString &msg) override;

signals:
    void nameChanged(QString name);

    void consoleMsgChanged(const QString &msg);

protected:
    QString m_name;
};

#endif
