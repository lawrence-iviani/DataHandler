#ifndef Test3_UI1_H
#define Test3_UI1_H

#include <datauihandlerui.h>
#include <QVBoxLayout>
#include <QLineEdit>

class Test3_UI1 : public DataUiHandlerUI
{
    Q_OBJECT
public:
    Test3_UI1(QWidget *parent = 0);

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

#endif // Test3_UI1_H
