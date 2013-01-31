#include "test2_data2.h"

Test2_data2::Test2_data2(QObject *parent) :
    QObject(parent)
{
    m_delegate=new Test2_Delegate2(new Test2_Property2(parent),new Test2_UI2(),parent);
}

Test2_data2::~Test2_data2() {
    delete m_delegate;
}
