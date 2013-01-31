#include "test1_data.h"

Test1_data::Test1_data(QObject *parent) :
    QObject(parent)
{
    m_delegate=new Test1_Delegate(new Test1_Property(parent),new Test1_UI(),parent);
}

Test1_data::~Test1_data() {
    delete m_delegate;
}
