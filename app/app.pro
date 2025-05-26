QT       += core gui network

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
    converter.cpp \
    dbinterface.cpp \
    main.cpp \
    mainwindow.cpp \
    noteinterface.cpp \
    progress.cpp \
    protocolmanager.cpp

HEADERS += \
    converter.h \
    dbinterface.h \
    general.h \
    mainwindow.h \
    noteinterface.h \
    progress.h \
    protocolmanager.h

FORMS += \
    ui/mainwindow.ui \
    ui/progress.ui \
    ui/noteinterface.ui \
    ui/dbinterface.ui \
    ui/converter.ui

# GENERAL UNITS
PRECOMPILED_HEADER += \
    general.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
