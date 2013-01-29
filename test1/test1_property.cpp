#include "test1_property.h"

Test1_Property::Test1_Property(QObject *parent) :
    DataUiHandlerProperty(parent)
{
    m_foo="foo not init";
}

void Test1_Property::setFoo(QString foo) {
    m_foo=foo;
    emit (fooChanged(foo));
}
