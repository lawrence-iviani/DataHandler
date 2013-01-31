#include "test2_ui2.h"

Test2_UI2::Test2_UI2(QWidget *parent) :
    Test2_UI1(parent)
{
    createAndLayoutWidget();

    //connect this  signal to emit the fooUIChangerd
    connect(m_pippo,SIGNAL(textChanged(QString)),this,SIGNAL(pippoUIChanged(QString)));

}

void Test2_UI2::createAndLayoutWidget() {
    QWidget *_widget=new QWidget(this);
    QVBoxLayout *_layout=new QVBoxLayout();
    _widget->setLayout(_layout);

    m_pippo=new QLineEdit(this);
    _layout->addWidget(m_pippo);
    this->setLayout((QLayout*)_layout);

    this->addWidget(_widget,"Test2_UI2");
}

//-------------- SLOTS --------------//
void Test2_UI2::pippoUIUpdate(QString foo) {
    m_pippo->setText(foo);
}

