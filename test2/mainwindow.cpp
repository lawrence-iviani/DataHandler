#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    qApp->setStyleSheet("QWidget { background-color: yellow } QLineEdit { selection-background-color : blue } QPushButton { background-color: red }");

    ui->setupUi(this);
    ui->centralWidget->setLayout(new QVBoxLayout());
 //   m_treeWidget=new QTreeWidget();
 //   m_treeWidget->hide();
    initData();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_data1;
    delete m_data2;
}

void MainWindow::initData() {

    //Adding widget data1
    QFrame * _f1=new QFrame(this);
    _f1->setLayout((QLayout*) new QVBoxLayout());
    _f1->setFrameStyle(QFrame::Panel | QFrame::Raised);
    m_data1=new Test2_data2(this);
    _f1->layout()->addWidget(m_data1->getWidget());

    //Adding Copy&paste widget for data1
    QWidget * _w1_cp=new QWidget(this);
    new QHBoxLayout(_w1_cp);
    QPushButton * _b1Copy=new QPushButton("Copy",_w1_cp);
    connect(_b1Copy,SIGNAL(clicked()),this,SLOT(copyData1Pressed()));
    QPushButton * _b1Paste=new QPushButton("Paste",_w1_cp);
    connect(_b1Paste,SIGNAL(clicked()),this,SLOT(pasteData1Pressed()));
    _w1_cp->layout()->setContentsMargins(5,0,5,0);
    _w1_cp->layout()->setMargin(0);
    _w1_cp->layout()->setSpacing(5);
    _w1_cp->layout()->addWidget(_b1Copy);
    _w1_cp->layout()->addWidget(_b1Paste);

    //Adding Export&Import widget for data1
    QWidget * _w1_ie=new QWidget(this);
    new QHBoxLayout(_w1_ie);
    QPushButton * _b1Export=new QPushButton("Export",_w1_ie);
    connect(_b1Export,SIGNAL(clicked()),this,SLOT(exportData1Pressed()));
    QPushButton * _b1Import=new QPushButton("Import",_w1_ie);
    connect(_b1Import,SIGNAL(clicked()),this,SLOT(importData1Pressed()));
    _w1_ie->layout()->setContentsMargins(5,0,5,0);
    _w1_ie->layout()->setMargin(0);
    _w1_ie->layout()->setSpacing(5);
    _w1_ie->layout()->addWidget(_b1Export);
    _w1_ie->layout()->addWidget(_b1Import);

    //Adding to frame layout
    _f1->layout()->setContentsMargins(5,0,5,0);
    _f1->layout()->setMargin(0);
    _f1->layout()->setSpacing(0);
    _f1->layout()->addWidget(_w1_cp);
    _f1->layout()->addWidget(_w1_ie);
    ui->centralWidget->layout()->addWidget(_f1);
//------------ DATA2 --------------

    //Adding widget data1
    QFrame * _f2=new QFrame(this);
    _f2->setLayout((QLayout*) new QVBoxLayout());
    _f2->setFrameStyle(QFrame::Panel | QFrame::Raised);
    m_data2=new Test2_data2(this);
    _f2->layout()->addWidget(m_data2->getWidget());

    //Adding Copy&paste widget for data2
    QWidget * _w2_cp=new QWidget(this);
    new QHBoxLayout(_w2_cp);
    QPushButton * _b2Copy=new QPushButton("Copy",_w2_cp);
    connect(_b2Copy,SIGNAL(clicked()),this,SLOT(copyData2Pressed()));
    QPushButton * _b2Paste=new QPushButton("Paste",_w2_cp);
    connect(_b2Paste,SIGNAL(clicked()),this,SLOT(pasteData2Pressed()));
    _w2_cp->layout()->setContentsMargins(5,0,5,0);
    _w2_cp->layout()->setMargin(0);
    _w2_cp->layout()->setSpacing(5);
    _w2_cp->layout()->addWidget(_b2Copy);
    _w2_cp->layout()->addWidget(_b2Paste);

    //Adding Export&Import widget for data2
    QWidget * _w2_ie=new QWidget(this);
    new QHBoxLayout(_w2_ie);
    QPushButton * _b2Export=new QPushButton("Export",_w2_ie);
    connect(_b2Export,SIGNAL(clicked()),this,SLOT(exportData2Pressed()));
    QPushButton * _b2Import=new QPushButton("Import",_w2_ie);
    connect(_b2Import,SIGNAL(clicked()),this,SLOT(importData2Pressed()));
    _w2_ie->layout()->setContentsMargins(5,0,5,0);
    _w2_ie->layout()->setMargin(0);
    _w2_ie->layout()->setSpacing(5);
    _w2_ie->layout()->addWidget(_b2Export);
    _w2_ie->layout()->addWidget(_b2Import);

    //Adding to frame layout
    _f2->layout()->setContentsMargins(5,0,5,0);
    _f2->layout()->setMargin(0);
    _f2->layout()->setSpacing(0);
    _f2->layout()->addWidget(_w2_cp);
    _f2->layout()->addWidget(_w2_ie);
    ui->centralWidget->layout()->addWidget(_f2);
}

void MainWindow::copyData1Pressed() {
    m_clipboard=m_data1->getDelegate()->getRootNode();
//    DomHelperUtility::parseDOMToQTreeWidget(&m_clipboard,m_treeWidget);
//    m_treeWidget->setWindowTitle("copyData1Pressed");
//    m_treeWidget->show();
//    m_treeWidget->expandAll();
}

void MainWindow::copyData2Pressed() {
    m_clipboard=m_data2->getDelegate()->getRootNode();
//    DomHelperUtility::parseDOMToQTreeWidget(&m_clipboard,m_treeWidget);
//    m_treeWidget->setWindowTitle("copyData2Pressed");
//    m_treeWidget->show();
//    m_treeWidget->expandAll();
}

void MainWindow::pasteData1Pressed() {
    ErrorMessage _err;
    if (!m_data1->getDelegate()->setClassByDomData(m_clipboard,&_err)) {
        PRINT_WARNING(_err.message());
    } else {
//        const QDomNode _rootNode=m_data1->getDelegate()->getRootNode();
//        DomHelperUtility::parseDOMToQTreeWidget(&_rootNode,m_treeWidget);
//        m_treeWidget->setWindowTitle("pasteData1Pressed");
//        m_treeWidget->show();
//        m_treeWidget->expandAll();
        PRINT_DEBUG_LEVEL(ErrorMessage::DEBUG_NOT_SO_IMPORTANT, _err.message());
    }
}

void MainWindow::pasteData2Pressed() {
    ErrorMessage _err;
    if (!m_data2->getDelegate()->setClassByDomData(m_clipboard,&_err)){
        PRINT_WARNING(_err.message());
    } else {
//        const QDomNode _rootNode=m_data2->getDelegate()->getRootNode();
//        DomHelperUtility::parseDOMToQTreeWidget(&_rootNode,m_treeWidget);
//        m_treeWidget->setWindowTitle("pasteData2Pressed");
//        m_treeWidget->show();
//        m_treeWidget->expandAll();
        PRINT_DEBUG_LEVEL(ErrorMessage::DEBUG_NOT_SO_IMPORTANT,_err.message());
    }
}

void MainWindow::importData1Pressed() {
    QDomDocument _doc;
    ErrorMessage _err;
    QString _fileName=QString("%1/").arg(FILE_PATH);
    _fileName = QFileDialog::getOpenFileName(this, "Load test1 file",
                                                   _fileName,
                                                   "XML file (*.xml *.XML)");

    if (!DomHelperUtility::load(_fileName,&_doc,&_err)) {
        PRINT_WARNING(_err.message());
    } else {
        if (!(m_data1->getDelegate()->setClassByDomData(_doc,&_err))) {
            PRINT_WARNING(_err.message());
        } else {
            PRINT_DEBUG_LEVEL(ErrorMessage::DEBUG_NOT_SO_IMPORTANT,ErrorMessage::DEBUG(Q_FUNC_INFO,"Imported document from file %1\n%2\n").arg(_fileName).arg(_doc.toString(4)));
        }
    }
}

void MainWindow::importData2Pressed() {
    QDomDocument _doc;
    ErrorMessage _err;
    QString _fileName=QString("%1/").arg(FILE_PATH);
    _fileName = QFileDialog::getOpenFileName(this, "Load test1 file",
                                                   _fileName,
                                                   "XML file (*.xml *.XML)");

    if (!DomHelperUtility::load(_fileName,&_doc,&_err)) {
        PRINT_WARNING(_err.message());
    } else {
        if (!(m_data2->getDelegate()->setClassByDomData(_doc,&_err))) {
            PRINT_WARNING(_err.message());
        } else {
            PRINT_DEBUG_LEVEL(ErrorMessage::DEBUG_NOT_SO_IMPORTANT,ErrorMessage::DEBUG(Q_FUNC_INFO,"Imported document from file %1\n%2\n").arg(_fileName).arg(_doc.toString(4)));
        }
    }
}

void MainWindow::exportData1Pressed() {
    QString _fileName=QString("%1/test1_data1.xml").arg(FILE_PATH);
    _fileName = QFileDialog::getSaveFileName(this, "Save test1 file",
                                                   _fileName,
                                                   "XML file (*.xml *.XML)");
    if (_fileName=="") return;
    ErrorMessage _err;
    DomHelperUtility::save(_fileName,m_data1->getDelegate()->getDomDocument(),&_err);
}

void MainWindow::exportData2Pressed() {
    QString _fileName=QString("%1/test1_data2.xml").arg(FILE_PATH);
    _fileName = QFileDialog::getSaveFileName(this, "Save test1 file",
                                                   _fileName,
                                                   "XML file (*.xml *.XML)");
    if (_fileName=="") return;
    ErrorMessage _err;
    DomHelperUtility::save(_fileName,m_data2->getDelegate()->getDomDocument(),&_err);
}
