#ifndef TEST2_DATA1_H
#define TEST2_DATA1_H

#include <QObject>
#include <data1/test2_delegate1.h>

class Test2_data1 : public QObject
{
    Q_OBJECT
public:
    explicit Test2_data1(QObject *parent = 0);
    virtual ~Test2_data1();

    QWidget * getWidget() {return (QWidget*)m_delegate->getUI(); }
    Test2_Property1* getProperty() {return (Test2_Property1*)m_delegate->getProperty();}
    Test2_Delegate1*  getDelegate() {return m_delegate;}
signals:

public slots:

private:
    Test2_Delegate1*  m_delegate;
};

#endif // TEST2_DATA1_H
