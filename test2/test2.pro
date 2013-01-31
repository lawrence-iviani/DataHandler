#-------------------------------------------------
#
# Project created by QtCreator 2013-01-12T22:21:09
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test1
TEMPLATE = app

DEFINES += DEBUG_LEVEL=3

SOURCES += data1/test2_data1.cpp \
    data1/test2_delegate1.cpp \
    data1/test2_ui1.cpp \
    data1/test2_property1.cpp \
    data2/test2_data2.cpp \
    data2/test2_property2.cpp \
    data2/test2_ui2.cpp \
    data2/test2_delegate2.cpp \
    main.cpp\
    mainwindow.cpp \


HEADERS  += data1/test2_data1.h \
    data1/test2_delegate1.h \
    data1/test2_property1.h \
    data1/test2_ui1.h \
    data2/test2_data2.h \
    data2/test2_delegate2.h \
    data2/test2_property2.h \
    data2/test2_ui2.h \
    mainwindow.h \

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
