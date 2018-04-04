#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T20:24:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = filmProjectManager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    person.cpp \
    project.cpp \
    projectreleased.cpp \
    projectunreleased.cpp \
    projectnowplaying.cpp \
    crew.cpp \
    material.cpp \
    audiotrack.cpp \
    frameaspect.cpp \
    packaging.cpp \
    dvd.cpp \
    bluray.cpp \
    dvdsinglesided.cpp \
    dvddoublesided.cpp \
    combobox.cpp \
    vhs.cpp \
    filminglocation.cpp \
    subtitles.cpp \
    dataholder.cpp

HEADERS += \
        mainwindow.h \
    person.h \
    project.h \
    projectreleased.h \
    projectunreleased.h \
    projectnowplaying.h \
    crew.h \
    material.h \
    audiotrack.h \
    frameaspect.h \
    packaging.h \
    dvd.h \
    bluray.h \
    dvdsinglesided.h \
    dvddoublesided.h \
    combobox.h \
    vhs.h \
    filminglocation.h \
    subtitles.h \
    dataholder.h

FORMS += \
        mainwindow.ui
