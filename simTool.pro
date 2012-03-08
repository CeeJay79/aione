#-------------------------------------------------
#
# Project created by QtCreator 2012-01-27T09:43:19
#
#-------------------------------------------------

QT      += core gui
QT      += opengl
TARGET   = simTool
TEMPLATE = app
SOURCES += main.cpp\
        mainwindow.cpp \
        node.cpp \
        edge.cpp \
        mechanicalnode.cpp \
        socialnode.cpp \
        search.cpp \
        feeder.cpp \
        astargraphsearch.cpp \
        offlinefeeder.cpp \
    simulator.cpp \
    heuristic.cpp \
    xmlwriter.cpp \
    xmlreader.cpp \
    graphfactory.cpp \
    geometricobject.cpp \
    graphicalnode.cpp \
    graphicaledge.cpp \
    observer.cpp \
    observable.cpp
HEADERS += mainwindow.h \
        node.hpp \
        edge.hpp \
        mechanicalnode.hpp \
        socialnode.hpp \
        search.hpp \
        feeder.hpp \
        astargraphsearch.hpp \
        offlinefeeder.hpp \
    simulator.hpp \
    heuristic.hpp \
    rapidxml_utils.hpp \
    rapidxml_print.hpp \
    rapidxml_iterators.hpp \
    rapidxml.hpp \
    xmlreader.hpp \
    xmlwriter.hpp \
    graphfactory.hpp \
    geometricobject.hpp \
    graphicalnode.hpp \
    graphicaledge.hpp \
    observer.hpp \
    observable.hpp
FORMS   += mainwindow.ui
CONFIG  += console
