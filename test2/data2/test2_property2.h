#ifndef GETSETTESTPROPERTY2_H
#define GETSETTESTPROPERTY2_H

#include <datauihandlerproperty.h>
#include "data1/test2_property1.h"

class Test2_Property2 : public Test2_Property1
{
    Q_OBJECT
    Q_PROPERTY(QString pippo READ pippo WRITE setPippo NOTIFY pippoChanged)
public:
    explicit Test2_Property2(QObject *parent = 0);
    
    QString pippo() {return m_pippo;}
signals:
    void pippoChanged(QString pippo);
public slots:
    void setPippo(QString pippo);
private:
    QString m_pippo;
};

#endif // GETSETTESTPROPERT2_H
