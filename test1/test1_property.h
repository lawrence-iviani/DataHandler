#ifndef GETSETTESTPROPERTY_H
#define GETSETTESTPROPERTY_H

#include <datauihandlerproperty.h>

class Test1_Property : public DataUiHandlerProperty
{
    Q_OBJECT
    Q_PROPERTY(QString foo READ foo WRITE setFoo NOTIFY fooChanged)
public:
    explicit Test1_Property(QObject *parent = 0);
    
    QString foo() {return m_foo;}
signals:
    void fooChanged(QString foo);
public slots:
    void setFoo(QString foo);
private:
    QString m_foo;
};

#endif // GETSETTESTPROPERTY_H
