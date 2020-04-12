TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        commands.cpp \
        communication.cpp \
        main.cpp \
        player_stats.cpp \
        tinarg.cpp

HEADERS += \
    commands.h \
    communication.h \
    player_stats.h \
    tinarg.h
