#ifndef GETSETTESTPROPERTY2_H
#define GETSETTESTPROPERTY2_H

#include <datauihandlerproperty.h>
#include "data1/test3_property1.h"

class Test3_Property2 : public Test3_Property1
{
    Q_OBJECT
    Q_PROPERTY(QString pippo READ pippo WRITE setPippo NOTIFY pippoChanged)
public:
    explicit Test3_Property2(QObject *parent=0);
    explicit Test3_Property2(Test3_Property1 *copyProperty,QObject *parent=0);
    
    QString pippo() {return m_pippo;}
signals:
    void pippoChanged(QString pippo);
public slots:
    void setPippo(QString pippo);
private:
    QString m_pippo;
};

#endif // GETSETTESTPROPERT2_H
