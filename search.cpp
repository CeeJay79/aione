#include "search.hpp"

Search::Search(Feeder* inFeeder)
{
    feeder = inFeeder;
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

void Search::addNodeToExploredSet(Node* inNode)
{
    numberOfNodesInExploredSet++;
    exploredSet.push_back(inNode);
}

Node* Search::popFrontier()
{
    Node* nodeToReturn = frontier[numberOfNodesInFrontier];
    numberOfNodesInFrontier--;
    frontier.erase(frontier.end());
    return nodeToReturn;
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
