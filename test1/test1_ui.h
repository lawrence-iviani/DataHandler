#ifndef TEST1_UI_H
#define TEST1_UI_H

#include <datauihandlerui.h>
#include <QVBoxLayout>
#include <QLineEdit>

class Test1_UI : public DataUiHandlerUI
{
    Q_OBJECT
public:
    Test1_UI(QWidget *parent = 0);

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

#endif // TEST1_UI_H
