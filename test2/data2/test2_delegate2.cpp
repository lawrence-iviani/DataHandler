#include "test2_delegate2.h"

Test2_Delegate2::Test2_Delegate2(Test2_Property2 * property, Test2_UI2 * ui , QObject *parent) :
    DataUiHandlerDelegate((DataUiHandlerProperty *)property,(DataUiHandlerUI*)ui,"Test2Document2","Test2_RootParams2",parent)
{
}


