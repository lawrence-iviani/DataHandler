#ifndef TEST2_DATA2_H
#define TEST2_DATA2_H

#include <QObject>
#include <data2/test2_delegate2.h>

class Test2_data2 : public QObject
{
    Q_OBJECT
public:
    explicit Test2_data2(QObject *parent = 0);
    virtual ~Test2_data2();

    QWidget * getWidget() {return (QWidget*)m_delegate->getUI(); }
    Test2_Property2* getProperty() {return (Test2_Property2*)m_delegate->getProperty();}
    Test2_Delegate2*  getDelegate() {return m_delegate;}
signals:

public slots:

private:
    Test2_Delegate2*  m_delegate;
};

#endif // TEST2_DATA2_H
