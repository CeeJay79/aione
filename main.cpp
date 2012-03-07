#include <QtGui/QApplication>
#include "mainwindow.h"
#include "astargraphsearch.hpp"
#include "offlinefeeder.hpp"
#include "socialnode.hpp"
#include "simulator.hpp"

#include <iostream>

#define GUI_DISPLAY 1

int main(int argc, char *argv[])
{
    // Declare Variables
    Heuristic heur;
//    OfflineFeeder<SocialNode> feeder("graph1.xml");
    OfflineFeeder<MechanicalNode> feeder("mechgraph2.xml");
    AStarGraphSearch search(&feeder);

    // GUI Display variables
#if GUI_DISPLAY == 1
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    Simulator* simPtr = w.getSimulatorPointer();
    simPtr->initializeNetwork(feeder.getMapping());
    search.registerObserver(simPtr);
#endif


    // Initialize Uninitialized Variables
    search.initInitNode(0);
    search.initGoalNode(10);
    search.initHeuristic(&heur);

    // Run the algorithm
    Node* solution = search.runSearch();

    if (solution == NULL)
        std::cout << "No path from start to goal node exists" << std::endl;
    else
    {
        #if GUI_DISPLAY == 1
        simPtr->drawSolutionPath(solution);
        #endif
        for (Node* i=solution; i!=NULL; i=i->parentNode)
        {
            std::cout << i->nodeID << " : " << i->getCurrentCost() <<  " : " << i->getHeuristicValue() << std::endl;
        }
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
