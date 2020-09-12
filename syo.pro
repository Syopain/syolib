TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
        include

SOURCES += \
        test/test.cpp

HEADERS += \
    include/Vector \
    include/vector.h
