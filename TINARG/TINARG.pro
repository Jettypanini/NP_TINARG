TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += ZMQ_STATIC
#DEFINES += NZMQT_LIB
LIBS += -L$$PWD/../lib -lnzmqt -lzmqlib -lws2_32 -lIphlpapi
INCLUDEPATH += $$PWD/../include

SOURCES += \
        commands.cpp \
        communication.cpp \
        main.cpp \
        statistics.cpp \
        tinarg.cpp

HEADERS += \
        commands.h \
        communication.h \
        statistics.h \
        tinarg.h \
        $$PWD/../include/nzmqt/nzmqt.hpp \
        $$PWD/../include/nzmqt/global.hpp \
        $$PWD/../include/nzmqt/impl.hpp
