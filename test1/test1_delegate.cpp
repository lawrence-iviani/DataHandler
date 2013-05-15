#include "test1_delegate.h"

Test1_Delegate::Test1_Delegate(Test1_Property * property, Test1_UI * ui , QObject *parent) :
    DataUiHandlerDelegate((DataUiHandlerProperty *)property,(DataUiHandlerUI*)ui,"Test1Document","Test1_RootParams",1,parent)
{
}


