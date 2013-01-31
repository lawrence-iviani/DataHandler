#include "test2_data1.h"

Test2_data1::Test2_data1(QObject *parent) :
    QObject(parent)
{
    m_delegate=new Test2_Delegate1(new Test2_Property1(parent),new Test2_UI1(),parent);
}

Test2_data1::~Test2_data1() {
    delete m_delegate;
}
