#include "Test2_Property1.h"

Test2_Property1::Test2_Property1(QObject *parent) :
    DataUiHandlerProperty(parent)
{
    m_foo="foo not init";
}

void Test2_Property1::setFoo(QString foo) {
    m_foo=foo;
    emit (fooChanged(foo));
}
