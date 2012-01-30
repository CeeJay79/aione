#include <QtGui/QApplication>
#include "mainwindow.h"
#include "offlinefeeder.hpp"
#include "astargraphsearch.hpp"

#define GUI_DISPLAY 1

int main(int argc, char *argv[])
{
    // Declare Variables

// Sebastien    OfflineSocialFeeder snetwork("/home/webaba/Dev/prai1/graph1.xml");





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