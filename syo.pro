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
    include/forward_list.h \
    include/forward_list.hpp \
    include/vector.h \
    include/vector.hpp
