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
    OfflineSocialFeeder feeder("graph1.xml");
    AStarGraphSearch search(&feeder);


    // Initialize Uninitialized Variables
    search.initInitNode(1);
    search.initGoalNode(10);
    search.initHeuristic(&heur);

    // Run the algorithm
    Node* solution = search.runSearch();

    for (Node* i=solution; i!=NULL; i=i->parentNode)
    {
        std::cout << i->nodeID << " : " << i->getCurrentCost() <<  " : " << i->getHeuristicValue() << std::endl;
    }


//    feeder.exportToXml("graphexport.xml");


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
