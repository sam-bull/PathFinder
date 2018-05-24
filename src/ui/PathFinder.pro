#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T17:33:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PathFinder
TEMPLATE = app


SOURCES += main.cpp\
        pathfinder.cpp\
    Coordinate.cpp \
    PathSet.cpp \
    PathQueue.cpp \
    PathStack.cpp \
    PathPriorityQueue.cpp \
    Path.cpp \
    Algorithm.cpp \
    mapwindow.cpp

HEADERS  += pathfinder.h\
    Coordinate.h \
    PathSet.h \
    PathQueue.h \
    PathStack.h \
    PathPriorityQueue.h \
    Path.h \
    Algorithm.h \
    BFS.h \
    DFS.h \
    AStar.h \
    mapwindow.h

FORMS    += pathfinder.ui \
    mapwindow.ui
