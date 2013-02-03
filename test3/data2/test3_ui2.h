#ifndef Test3_UI2_H
#define Test3_UI2_H

#include <datauihandlerui.h>
#include <QVBoxLayout>
#include <QLineEdit>
#include "data1/test3_ui1.h"

class Test3_UI2 : public Test3_UI1
{
    Q_OBJECT
public:
    Test3_UI2(QWidget *parent = 0);

signals:
    void pippoUIChanged(QString foo);

public slots:
    void pippoUIUpdate(QString foo);

private:
    void createAndLayoutWidget();
    QLineEdit * m_pippo;
};

#endif // Test3_UI2_H
