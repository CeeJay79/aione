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
    offlinesocialfeeder.cpp \
    xmlwriter.cpp \
    xmlreader.cpp \
    graphfactory.cpp
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
    offlinesocialfeeder.hpp \
    rapidxml_utils.hpp \
    rapidxml_print.hpp \
    rapidxml_iterators.hpp \
    rapidxml.hpp \
    xmlreader.hpp \
    xmlwriter.hpp \
    graphfactory.hpp
FORMS   += mainwindow.ui
CONFIG  += console
