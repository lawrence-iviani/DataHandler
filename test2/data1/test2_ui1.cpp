#include "Test2_UI1.h"

Test2_UI1::Test2_UI1(QWidget *parent) :
    DataUiHandlerUI(parent)
{
    createAndLayoutWidget();

    //connect this  signal to emit the fooUIChangerd
    connect(m_foo,SIGNAL(textChanged(QString)),this,SIGNAL(fooUIChanged(QString)));


    //And in a very similar way... for description that is inerithed
    connect(m_description,SIGNAL(textChanged(QString)),this,SIGNAL(descriptionUIChanged(QString)));
}

void Test2_UI1::createAndLayoutWidget() {
    QWidget *_widget=new QWidget(this);
    QVBoxLayout *_layout=new QVBoxLayout();
    _widget->setLayout(_layout);

    m_uuid=new QLineEdit(this);
    m_uuid->setReadOnly(true);
    m_description=new QLineEdit(this);
    m_foo=new QLineEdit(this);

    _layout->addWidget(m_uuid);
    _layout->addWidget(m_description);
    _layout->addWidget(m_foo);

    this->addWidget(_widget,"Test2_UI1");
}

//-------------- SLOTS --------------//
void Test2_UI1::fooUIUpdate(QString foo) {
    m_foo->setText(foo);
}

void Test2_UI1::descriptionUIUpdate(QString description) {
    m_description->setText(description);
}

void Test2_UI1::uuidUIUpdate(QUuid uuid) {
    m_uuid->setText(uuid.toString());
    int _minLen=0.7*m_uuid->font().pointSize()* m_uuid->text().length();// a trick...
    m_uuid->setMinimumSize(_minLen,20);
}
