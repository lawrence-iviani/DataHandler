#ifndef Test3_DATA1_H
#define Test3_DATA1_H

#include <QObject>
#include <datauihandlerdelegate.h>
#include "data1/test3_property1.h"
#include "data1/test3_ui1.h"

class Test3_data1 : public QObject
{
    Q_OBJECT
public:
    explicit Test3_data1(QObject *parent = 0);
    virtual ~Test3_data1();

    DataUiHandlerDelegate* getDelegate() {return m_delegate;}

signals:

public slots:

protected:
    void connectSignals();
private:
    DataUiHandlerDelegate *  m_delegate;

private slots:
    /**
     * @brief upperCaseFoo This Method change to uppercase the property foo.
     */
    void upperCaseFoo();
};

#endif // Test3_DATA1_H
