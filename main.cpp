#include <QtGui/QApplication>
#include "mainwindow.h"
#include "offlinesocialfeeder.hpp"
#include "astargraphsearch.hpp"

#include <iostream>
#include "simulator.hpp"


#define GUI_DISPLAY 0

int main(int argc, char *argv[])
{
    // Declare Variables
    Heuristic heur;
    OfflineSocialFeeder feeder("graph2.xml");
    AStarGraphSearch search(&feeder);

    feeder.exportToXml("graphexport.xml");

    // Initialize Uninitialized Variables
    search.initInitNode(295);
    search.initGoalNode(294);
    search.initHeuristic(&heur);

    // Run the algorithm
       Node* solution = search.runSearch();
    std::cout << (solution->parentNode)->getCurrentCost() << std::endl;



//    for (Node* i=solution; i!=NULL; i=i->parentNode)
//    {
//        std::cout << i->nodeID << std::endl;
//    }





    // Save result in file
//    feeder.exportToXml("graph2.xml");


    // GUI Display variables
#if GUI_DISPLAY == 1
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    Simulator x;
    x.show();
#endif

    // Cleanup and preperation to exit program
#if GUI_DISPLAY == 1
    return a.exec();
#else
    return 0;
#endif
}
