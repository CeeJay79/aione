#include "search.hpp"

Search::Search()
{
    numberOfNodesInFrontier    = 0;
    numberOfNodesInExploredSet = 0;
}

void Search::initInitNode(int inInitNodeID)
{
    initNodeID = inInitNodeID;
}

void Search::initGoalNode(int inGoalNodeID)
{
    goalNodeID = inGoalNodeID;
}

void Search::addNodeToFrontier(Node* inNode)
{
    numberOfNodesInFrontier++;
    // Sort and then add to frontier
}

void Search::addNodeToExploredSet(Node * inNode)
{
    numberOfNodesInExploredSet++;
    exploredSet.push_back(inNode);
}

bool Search::goalTest(Node* nodeToBeTested)
{
    if (goalNodeID == nodeToBeTested->getNodeID())
        return 1;
    else
        return 0;
}

std::vector <Node*> Search::getFrontier()
{
    return frontier;
}
