TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    modules.cpp \
    environment.cpp \
    corethread.cpp

HEADERS += \
    modules.h \
    environment.h \
    libss.h \
    corethread.h
