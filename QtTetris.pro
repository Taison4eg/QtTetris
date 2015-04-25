# Файл проекта
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTetris
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamesettings.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    gamesettings.h \
    about.h

FORMS    += mainwindow.ui \
    gamesettings.ui \
    about.ui
