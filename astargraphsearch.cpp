#include "astargraphsearch.hpp"

AStarGraphSearch::AStarGraphSearch(Feeder* inFeeder) : Search(inFeeder)
{
}

Node* AStarGraphSearch::runSearch()
{
    // Declare Variables
    bool  goalFound;
    Node* currentNode;
    Node* initialNode;
    std::vector <Node*> nodeSuccessors;
    std::vector <Edge*> edgeSuccessors;

    // Initialize Variables
    goalFound = 0;
    initialNode = feeder->getNode(initNodeID);
    initialNode->setCurrentCost(0);

    addNodeToFrontier(initialNode,0);

    while (frontier.nodes.size() != 0)
    {

        currentNode = popFrontier();
        currentNode->setExplored(1);


        goalFound = goalTest(currentNode);
        if (goalFound)
        {
            break;
        }

        addNodeToExploredSet(currentNode,0/*This is not important for explored set*/);

        feeder->getSuccessors(currentNode,&edgeSuccessors);
        int numberOfSuccessors = edgeSuccessors.size();
        nodeSuccessors.resize(numberOfSuccessors);

        int row;
        double minF = 999999999999;
        for (int i=0; i<numberOfSuccessors; i++)
        {
            double g;
            double f;

            nodeSuccessors[i] = edgeSuccessors[i]->getTarget(); // This is very shit job by shit man

            g = currentNode->getCurrentCost() + edgeSuccessors[i]->getCost();
            f = heuristic->evaluateHeuristic(g,nodeSuccessors[i]);
            nodeSuccessors[i]->setCurrentCost(g);
            nodeSuccessors[i]->setHeuristicValue(f);

            if (f < minF)
            {
                minF = f;
                row  = i;
            }

            if (isNodeInExploredSet(nodeSuccessors[i]) == 0)
            {
                int jj = isNodeInFrontier(nodeSuccessors[i]);
                if (jj == 0)
                {
                    nodeSuccessors[i]->setParent(currentNode);
                    addNodeToFrontier(nodeSuccessors[i],f);
                }
                else if (jj > 0)
                {
                    nodeSuccessors[i]->setParent(currentNode);
                    frontier.nodes[jj] = nodeSuccessors[i];
                    frontier.costs[jj] = nodeSuccessors[i]->getHeuristicValue();
                }
            }
        }
    }

    if (frontier.nodes.size() == 0)
        return NULL;
    else
        return currentNode;
}

void AStarGraphSearch::sortPriorityQueue()
{
}

std::vector <Node*> AStarGraphSearch::getExploredSet()
{
    return exploredSet.nodes;
}
