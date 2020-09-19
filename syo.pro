TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
        include

SOURCES += \
        source/big_integer.cpp \
        test/test.cpp

HEADERS += \
    include/big_integer.h \
    include/vector.h \
    include/vector.hpp
