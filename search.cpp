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

void Search::initHeuristic(Heuristic* inHeuristic)
{
    heuristic = inHeuristic;
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
    bool leastExpensive(1);

    for (int i=0;i<numberOfNodesInFrontier;i++)
    {
        if (inCost > frontier.costs[i])
        {
            leastExpensive = 0;
            frontier.nodes.insert(posNode + i,inNode);
            frontier.costs.insert(posCost + i,inCost);
            break;
        }
    }

    if (leastExpensive)
    {
        frontier.nodes.push_back(inNode);
        frontier.costs.push_back(inCost);
    }
    /*
    if (mostExpensive)
    {
        frontier.nodes.insert(posNode,inNode);
        frontier.costs.insert(posCost,inCost);
    }
    */
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

    Node* nodeToReturn = frontier.nodes[numberOfNodesInFrontier-1];
    numberOfNodesInFrontier--;

    frontier.nodes.erase(frontier.nodes.end()-1);
    frontier.costs.erase(frontier.costs.end()-1);

    return nodeToReturn;
}

int Search::isNodeInFrontier(Node* inNode)
{
    //  0: Not in frontier
    // -1: Present in frontier but frontier is more optimal
    //  n: Present in frontier at position n and frontier is not optimal

    for (int i=0;i<numberOfNodesInFrontier;i++)
    {
        if (inNode == frontier.nodes[i])
        {
            if (frontier.nodes[i]->getHeuristicValue() < inNode->getHeuristicValue())
                return -1;
            else
                return i;
        }
    }

    return 0;
}

int Search::isNodeInExploredSet(Node* inNode)
{
    //  0: Not in explored set
    // -1: Present in explored set and inNode is more optimal
    // -2: Present in explored set but explored set is not more optimal

    for (int i=0;i<numberOfNodesInExploredSet;i++)
    {
        if (inNode == exploredSet.nodes[i])
        {
            if (exploredSet.nodes[i]->getHeuristicValue() < inNode->getHeuristicValue())
                return -2;
            else
                return -1;
        }
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
    return frontier.nodes;
}
