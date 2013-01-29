#include "test1_data.h"

Test1_data::Test1_data(QObject *parent) :
    QObject(parent)
{
    m_ui=new Test1_UI();
    m_property=new Test1_Property(parent);
    m_delegate=new Test1_Delegate(m_property,m_ui,parent);
}

Test1_data::~Test1_data() {
    delete m_delegate;
    delete m_property;
}
