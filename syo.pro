TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
        include

SOURCES += \
        exercise/exercise_2.cpp \
        exercise/exercise_3.cpp \
        exercise/exercise_4.cpp \
        exercise/exercise_6.cpp \
        source/big_integer.cpp \
        source/calculate.cpp \
        test/test.cpp \
        test/test_forward_list.cpp \
        test/test_vector.cpp

HEADERS += \
    include/algorithm.h \
    include/big_integer.h \
    include/forward_list.h \
    include/forward_list.hpp \
    include/stack.h \
    include/stack.hpp \
    include/vector.h \
    include/vector.hpp \
    test/test.hpp
