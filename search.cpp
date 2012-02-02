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

void Search::addNodeToFrontier(Node* inNode,double inCost)
{
    numberOfNodesInFrontier++;

    if (numberOfNodesInFrontier == 1)
    {
        frontier.nodes.push_back(inNode);
        frontier.costs.push_back(inCost);
        return;
    }

    std::vector <Node*>::iterator  posNode;
    std::vector <double>::iterator posCost;
    posNode = frontier.nodes.begin();
    posCost = frontier.costs.begin();
    bool mostExpensive(1);
    for (int i=0;i<numberOfNodesInFrontier;i++)
    {
        if (inCost < frontier.costs[i])
        {
            mostExpensive = 0;
            frontier.nodes.insert(posNode + i + 1,inNode);
            frontier.costs.insert(posCost + i + 1,inCost);
        }
    }
    if (mostExpensive)
    {
        frontier.nodes.insert(posNode,inNode);
        frontier.costs.insert(posCost,inCost);
    }
}

void Search::addNodeToExploredSet(Node* inNode,double inCost)
{
    numberOfNodesInExploredSet++;
    exploredSet.nodes.push_back(inNode);
    exploredSet.costs.push_back(inCost);
}

Node* Search::popFrontier()
{
    if (numberOfNodesInFrontier == 0)
        return NULL;

    Node* nodeToReturn = frontier.nodes[numberOfNodesInFrontier];
    numberOfNodesInFrontier--;

    frontier.nodes.erase(frontier.nodes.end());
    frontier.costs.erase(frontier.costs.end());

    return nodeToReturn;
}

bool Search::isNodeInExploredSetOrFrontier(Node* inNode)
{
    for (int i=0;i<numberOfNodesInExploredSet;i++)
    {
        if (inNode == exploredSet.nodes[i])
            return 1;
    }

    for (int i=0;i<numberOfNodesInFrontier;i++)
    {
        if (inNode == frontier.nodes[i])
            return 1;
    }

    return 0;
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
//    return 0;
//    return frontier.nodes;
}
