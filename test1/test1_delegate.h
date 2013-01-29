#ifndef TEST1_DELEGATE_H
#define TEST1_DELEGATE_H

#include <datauihandlerdelegate.h>
#include <test1_ui.h>
#include <test1_property.h>

class Test1_Delegate : public DataUiHandlerDelegate
{
public:
    Test1_Delegate(Test1_Property * property, Test1_UI * ui , QObject *parent = 0);
};

#endif // TEST1_DELEGATE_H
