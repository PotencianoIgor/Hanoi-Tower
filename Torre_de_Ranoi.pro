#-------------------------------------------------
#
# Project created by QtCreator 2015-03-03T14:05:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Torre_de_Ranoi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pilha.cpp \
    jogo.cpp

HEADERS  += mainwindow.h \
    pilha.h \
    jogo.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
