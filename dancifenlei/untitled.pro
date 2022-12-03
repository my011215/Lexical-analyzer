#-------------------------------------------------
#
# Project created by QtCreator 2022-05-11T10:15:49
#
#-------------------------------------------------

QT       += core gui
QT += sql
#CONFIG+= console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainwindowmenu.cpp \
    words.cpp \
    zifu.cpp \
    dialog_chaxun.cpp \
    dialog_xiugai.cpp \
    dfa.cpp \
    thewords.cpp \
    guanjianzi.cpp \
    xiugai_gjz.cpp \
    dancifenlei.cpp \
    danzifufjf.cpp \
    staticdfa.cpp \
    cifaguize.cpp

HEADERS  += mainwindow.h \
    mainwindowmenu.h \
    words.h \
    zifu.h \
    dialog_chaxun.h \
    dialog_xiugai.h \
    dfa.h \
    thewords.h \
    guanjianzi.h \
    xiugai_gjz.h \
    dancifenlei.h \
    danzifufjf.h \
    staticdfa.h \
    cifaguize.h

FORMS    += mainwindow.ui \
    mainwindowmenu.ui \
    words.ui \
    dialog_chaxun.ui \
    dialog_xiugai.ui \
    dfa.ui \
    thewords.ui \
    xiugai_gjz.ui \
    dancifenlei.ui \
    danzifufjf.ui \
    staticdfa.ui \
    cifaguize.ui

RESOURCES += \
    picture.qrc

DISTFILES +=
