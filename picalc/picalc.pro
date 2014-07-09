#-------------------------------------------------
#
# Project created by QtCreator 2010-11-23T20:55:07
#
#-------------------------------------------------

QT       += core gui

TARGET = picalc
TEMPLATE = app

QMAKE_CFLAGS += -march=native -O3
QMAKE_CXXFLAGS += -march=native -O3

LIBS += -l arprec

SOURCES += main.cpp\
    calculator.cpp \
    picalc.cpp \
    SFMT.c

HEADERS  += calculator.h \
    picalc.h \
    SFMT.h
