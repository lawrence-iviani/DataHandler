#ifndef TEST1_DATA_H
#define TEST1_DATA_H

#include <QObject>
#include <test1_delegate.h>

class Test1_data : public QObject
{
    Q_OBJECT
public:
    explicit Test1_data(QObject *parent = 0);
    virtual ~Test1_data();

    QWidget * getWidget() {return (QWidget*)m_ui;}
    Test1_Property* getProperty() {return m_property;}
    Test1_Delegate*  getDelegate() {return m_delegate;}
signals:

public slots:

private:
    Test1_UI* m_ui;
    Test1_Property* m_property;
    Test1_Delegate*  m_delegate;
};

#endif // TEST1_DATA_H
