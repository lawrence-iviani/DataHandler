#ifndef GETSETTESTPROPERTY1_H
#define GETSETTESTPROPERTY1_H

#include <datauihandlerproperty.h>

class Test2_Property1 : public DataUiHandlerProperty
{
    Q_OBJECT
    Q_PROPERTY(QString foo READ foo WRITE setFoo NOTIFY fooChanged)
public:
    explicit Test2_Property1(QObject *parent = 0);
    
    QString foo() {return m_foo;}
signals:
    void fooChanged(QString foo);
public slots:
    void setFoo(QString foo);
private:
    QString m_foo;
};

#endif // GETSETTESTPROPERTY1_H
