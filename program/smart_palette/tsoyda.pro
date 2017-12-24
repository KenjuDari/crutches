#-------------------------------------------------
#
# Project created by QtCreator 2017-12-17T13:45:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tsoyda
TEMPLATE = app


SOURCES += main.cpp\
        beginner.cpp \
    myimage.cpp \
    myverticallayout.cpp \
    mybutton.cpp \
    mycolorcell.cpp \
    mygridlayout.cpp \
    myrunningcell.cpp \
    mylabel.cpp \
    mystar.cpp

HEADERS  += beginner.h \
    myimage.h \
    myverticallayout.h \
    mybutton.h \
    mycolorcell.h \
    mygridlayout.h \
    myrunningcell.h \
    mylabel.h \
    mystar.h

FORMS    += beginner.ui

RESOURCES += \
    resource.qrc
