#include <QtGui/QApplication>
#include "mainwindow.h"
#include "offlinesocialfeeder.hpp"
#include "astargraphsearch.hpp"

#define GUI_DISPLAY 1

int main(int argc, char *argv[])
{
    // Declare Variables

    OfflineSocialFeeder snetwork("/home/webaba/Dev/aione/graph1.xml");

    snetwork.exportToXml("/home/webaba/Dev/aione/graph2.xml");

    // GUI Display variables
#if GUI_DISPLAY == 1
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
#endif

    // Cleanup and preperation to exit program
#if GUI_DISPLAY == 1
    return a.exec();
#else
    return 0;
#endif
}
