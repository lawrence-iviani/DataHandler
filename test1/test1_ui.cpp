#include "test1_ui.h"

Test1_UI::Test1_UI(QWidget *parent) :
    DataUiHandlerUI(parent)
{
    createAndLayoutWidget();

    //connect this  signal to emit the fooUIChangerd
    connect(m_foo,SIGNAL(textChanged(QString)),this,SIGNAL(fooUIChanged(QString)));


    //And in a very similar way... for description that is inerithed
    connect(m_description,SIGNAL(textChanged(QString)),this,SIGNAL(descriptionUIChanged(QString)));
}

void Test1_UI::createAndLayoutWidget() {
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

    this->addWidget(_widget,"Test1_UI");
}

//-------------- SLOTS --------------//
void Test1_UI::fooUIUpdate(QString foo) {
    m_foo->setText(foo);
}

void Test1_UI::descriptionUIUpdate(QString description) {
    m_description->setText(description);
}

void Test1_UI::uuidUIUpdate(QUuid uuid) {
    m_uuid->setText(uuid.toString());   
    int _minLen=0.7*m_uuid->font().pointSize()* m_uuid->text().length();// a trick...
    m_uuid->setMinimumSize(_minLen,20);
}

