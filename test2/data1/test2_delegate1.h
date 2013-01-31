#ifndef TEST2_DELEGATE1_H
#define TEST2_DELEGATE1_H

#include <datauihandlerdelegate.h>
#include <data1/test2_ui1.h>
#include <data1/test2_property1.h>

class Test2_Delegate1 : public DataUiHandlerDelegate
{
public:
    Test2_Delegate1(Test2_Property1 * property, Test2_UI1 * ui , QObject *parent = 0);

};

#endif // TEST2_DELEGATE1_H
