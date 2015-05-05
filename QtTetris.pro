# Файл проекта
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTetris
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamesettings.cpp \
    about.cpp \
    game.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    gamesettings.h \
    about.h \
    game.h \
    settings.h

FORMS    += mainwindow.ui \
    gamesettings.ui \
    about.ui
