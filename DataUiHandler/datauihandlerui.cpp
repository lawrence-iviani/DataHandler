#include "datauihandlerui.h"

DataUiHandlerUI::DataUiHandlerUI(QWidget *parent) :
    QWidget(parent)
{
    this->setObjectName("DataUiHandlerUI");
    this->setLayout(new QVBoxLayout());
    this->layout()->setSpacing(6);
    this->layout()->setSizeConstraint(QLayout::SetMinimumSize);
}

void DataUiHandlerUI::addWidget(QWidget *widget, const QString &label, uint priority) {
    PRINT_DEBUG_LEVEL (ErrorMessage::DEBUG_NOT_SO_IMPORTANT,ErrorMessage::DEBUG(Q_FUNC_INFO,
                 QString("Adding widget %1 @%2 to this@%3")
                .arg(label)
                .arg(QString::number((qlonglong)widget,16))
                .arg(QString::number((qlonglong)this,16))
                ));
    Q_UNUSED(priority);
    QVBoxLayout *_layout=(QVBoxLayout *) this->layout();
    QLabel * _label=new QLabel(label,this);
    QFrame * _frame=new QFrame(this);
    _frame->setLayout(new QVBoxLayout());
    _frame->setFrameShape(QFrame::StyledPanel);
    _frame->setFrameShadow(QFrame::Raised);
    _frame->layout()->setSpacing(1);
    _frame->layout()->setSizeConstraint(QLayout::SetMinimumSize);
    _frame->layout()->addWidget(widget);

    //Layouting
    _layout->addWidget(_label,1,Qt::AlignBottom|Qt::AlignLeft);
    _layout->addWidget(_frame,2,Qt::AlignTop|Qt::AlignLeft);

}
