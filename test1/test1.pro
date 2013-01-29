#-------------------------------------------------
#
# Project created by QtCreator 2013-01-12T22:21:09
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        test1_ui.cpp \
        test1_delegate.cpp \
        test1_property.cpp \
    test1_data.cpp


HEADERS  += mainwindow.h \
        test1_ui.h \
        test1_delegate.h \
        test1_property.h \
    test1_data.h

FORMS    += mainwindow.ui

CONFIG(debug, debug|release) {
    DESTDIR = debug
    OBJECTS_DIR = debug/obj
    MOC_DIR = debug/moc
    LIBS += -L$$PWD/../ErrorMessage/debug/ -lErrorMessage
    LIBS += -L$$PWD/../DataUiHandler/debug/ -lDataUiHandler
} else {
    DESTDIR = release
    OBJECTS_DIR = release/obj
    MOC_DIR = release/moc
    LIBS += -L$$PWD/../ErrorMessage/release/ -lErrorMessage
    LIBS += -L$$PWD/../DataUiHandler/release/ -lDataUiHandler
}

INCLUDEPATH += $$PWD/../DataUiHandler
DEPENDPATH += $$PWD/../DataUiHandler
INCLUDEPATH += $$PWD/../ErrorMessage
DEPENDPATH += $$PWD/../ErrorMessage
