#include "test2_delegate1.h"

Test2_Delegate1::Test2_Delegate1(Test2_Property1 * property, Test2_UI1 * ui , QObject *parent) :
    DataUiHandlerDelegate((DataUiHandlerProperty *)property,(DataUiHandlerUI*)ui,"Test1Document","Test1_RootParams",parent)
{
}


