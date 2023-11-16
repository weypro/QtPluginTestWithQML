#ifndef IPLUGINMODULEBASE_H
#define IPLUGINMODULEBASE_H

#include <QObject>
#include <QQmlEngine>
class IPluginModuleBase : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

    //    QML_ELEMENT
public:
    explicit IPluginModuleBase(QObject *parent = nullptr);

    virtual QString name() const;
    virtual void setName(const QString &name);

signals:
    void nameChanged(QString name);

protected:
    QString m_name;
};

Q_DECLARE_METATYPE(IPluginModuleBase)

#endif // IPLUGINMODULEBASE_H
