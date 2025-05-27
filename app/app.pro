QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += PRECOMPILED_HEADER

debug {
    DEFINES += QT_DEBUG
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gui_src\converter.cpp \
    gui_src\dbinterface.cpp \
    dbmanager.cpp \
    logger.cpp \
    main.cpp \
    gui_src\mainwindow.cpp \
    gui_src\noteinterface.cpp \
    gui_src\progress.cpp \
    gui_src\newland.cpp \
    protocolmanager.cpp \
    gui_src\dialog.cpp

HEADERS += \
    gui_src\converter.h \
    gui_src\dbinterface.h \
    dbmanager.h \
    general.h \
    gui_src\mainwindow.h \
    gui_src\noteinterface.h \
    gui_src\progress.h \
    gui_src\newland.h \
    logger.h \
    protocolmanager.h \
    gui_src\dialog.h

FORMS += \
    ui/dialog.ui \
    ui/newland.ui \
    ui/mainwindow.ui \
    ui/progress.ui \
    ui/noteinterface.ui \
    ui/dbinterface.ui \
    ui/converter.ui

# GENERAL UNITS
PRECOMPILED_HEADER += \
    general.h

# generate .exe near .pro
DESTDIR += ./
UI_DIR = ui/
TARGET = cashtracker

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
