#ifndef Test3_DATA2_H
#define Test3_DATA2_H

#include <QObject>
#include <data1/test3_data1.h>
#include "data2/test3_property2.h"
#include "data2/test3_ui2.h"

class DataUiHandlerDelegate;

class Test3_data2 : public Test3_data1
{
    Q_OBJECT
public:
    explicit Test3_data2(QObject *parent = 0);
    virtual ~Test3_data2();

signals:

public slots:

private:
    DataUiHandlerDelegate*  m_delegate;

};

#endif // Test3_DATA2_H
