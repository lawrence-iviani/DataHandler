#ifndef TEST2_DELEGATE2_H
#define TEST2_DELEGATE2_H

#include <datauihandlerdelegate.h>
#include "test2_ui2.h"
#include "test2_property2.h"

class Test2_Delegate2 : public DataUiHandlerDelegate
{
public:
    Test2_Delegate2(Test2_Property2 * property, Test2_UI2 * ui , QObject *parent = 0);
};

#endif // TEST2_DELEGATE2_H
