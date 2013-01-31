#ifndef TEST2_UI2_H
#define TEST2_UI2_H

#include <datauihandlerui.h>
#include <QVBoxLayout>
#include <QLineEdit>
#include "data1/test2_ui1.h"

class Test2_UI2 : public Test2_UI1
{
    Q_OBJECT
public:
    Test2_UI2(QWidget *parent = 0);

signals:
    void pippoUIChanged(QString foo);

public slots:
    void pippoUIUpdate(QString foo);

private:
    void createAndLayoutWidget();
    QLineEdit * m_pippo;
};

#endif // TEST2_UI2_H
