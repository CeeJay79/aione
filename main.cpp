#include <QtGui/QApplication>
#include "mainwindow.h"
#include "astargraphsearch.hpp"
#include "offlinefeeder.hpp"
#include "socialnode.hpp"
#include <iostream>
#include "simulator.hpp"


#define GUI_DISPLAY 1

int main(int argc, char *argv[])
{
    // GUI Display variables
#if GUI_DISPLAY == 1
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    Simulator* simPtr = w.getSimulatorPointer();
#endif


    // Declare Variables
    Heuristic heur;
//    OfflineFeeder<SocialNode> feeder("graph1.xml");
    OfflineFeeder<MechanicalNode> feeder("mechgraph.xml");
    AStarGraphSearch search(&feeder);




#if GUI_DISPLAY == 1
    search.registerObserver(simPtr);
#endif


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


    // Cleanup and preperation to exit program
#if GUI_DISPLAY == 1
    return a.exec();
#else
    return 0;
#endif
}
