#ifndef TEST2_UI1_H
#define TEST2_UI1_H

#include <datauihandlerui.h>
#include <QVBoxLayout>
#include <QLineEdit>

class Test2_UI1 : public DataUiHandlerUI
{
    Q_OBJECT
public:
    Test2_UI1(QWidget *parent = 0);

signals:
    void fooUIChanged(QString foo);

public slots:
    void fooUIUpdate(QString foo);
    void descriptionUIUpdate(QString description);
    void uuidUIUpdate(QUuid uuid);

private:
    void createAndLayoutWidget();

    QLineEdit * m_description;
    QLineEdit * m_uuid;
    QLineEdit * m_foo;
};

#endif // TEST2_UI1_H
