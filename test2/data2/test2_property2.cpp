#include "data2/test2_property2.h"

Test2_Property2::Test2_Property2(QObject *parent) :
    Test2_Property1(parent)
{
    m_pippo="pippo not paperino";
}

void Test2_Property2::setPippo(QString pippo) {
    m_pippo=pippo;
    emit (pippoChanged(pippo));
}
