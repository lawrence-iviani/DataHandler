#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFileDialog>
#include <QTreeWidget>
#include "data1/test3_data1.h"
#include "data2/test3_data2.h"
#include  "XML_utils/domhelperutility.h"

#define FILE_PATH "/Volumes/MYDATA/QT_TEST/gettersetter/test1_testfiles"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void copyData1Pressed();
    void pasteData1Pressed();
    void copyData2Pressed();
    void pasteData2Pressed();

    void importData1Pressed();
    void exportData1Pressed();
    void importData2Pressed();
    void exportData2Pressed();

private:
    Ui::MainWindow *ui;

    void initData();

    Test3_data2 * m_data1;
    Test3_data2 * m_data2;
    QDomNode m_clipboard;
    QTreeWidget * m_treeWidget;
};

#endif // MAINWINDOW_H
