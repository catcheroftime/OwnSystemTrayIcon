QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OwnSystemTrayIcon
TEMPLATE = app
RC_FILE = icon.rc

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp\
        mainwindow.cpp \
    ownsyetemtrayicon.cpp

HEADERS  += mainwindow.h \
    ownsyetemtrayicon.h

FORMS    += mainwindow.ui

DISTFILES += \
    $$PWD/logo.ico \
    $$PWD/icon.rc

RESOURCES += \
    resource.qrc
