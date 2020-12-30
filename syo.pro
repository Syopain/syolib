CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += \
        include

SOURCES += \
        design/design_1.cpp \
        design/design_2.cpp \
        design/design_3.cpp \
        design/design_4.cpp \
        design/design_5.cpp \
        design/design_6.cpp \
        design/design_7.cpp \
        design/design_8.cpp \
        exercise/exercise_02.cpp \
        exercise/exercise_03.cpp \
        exercise/exercise_04.cpp \
        exercise/exercise_06.cpp \
        exercise/exercise_10.cpp \
        exercise/exercise_11.cpp \
        source/algorithm.cpp \
        source/polynomial.cpp \
        source/big_integer.cpp \
        source/calculate.cpp \
        source/syo_math.cpp \
        test/test.cpp \
        test/test_binary_tree.cpp \
        test/test_forward_list.cpp \
        test/test_vector.cpp

HEADERS += \
    design/design.h \
    exercise/exercise.h \
    include/algorithm.h \
    include/big_integer.h \
    include/binary_tree.h \
    include/binary_tree.hpp \
    include/forward_list.h \
    include/forward_list.hpp \
    include/polynomial.h \
    include/stack.h \
    include/stack.hpp \
    include/syo_math.h \
    include/vector.h \
    include/vector.hpp \
    test/test.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
