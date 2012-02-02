#include "astargraphsearch.hpp"

AStarGraphSearch::AStarGraphSearch(Feeder* inFeeder) : Search(inFeeder)
{
}

void AStarGraphSearch::initHeuristic()
{

}

void AStarGraphSearch::runSearch()
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

    addNodeToFrontier(initialNode,0);

    while (true)
    {
        currentNode = popFrontier();

        goalFound = goalTest(currentNode);
        if (goalFound)
        {
            break;
        }

        addNodeToExploredSet(currentNode,0);

        feeder->getSuccessors(currentNode,edgeSuccessors);
        int numberOfSuccessors = edgeSuccessors.size();
        nodeSuccessors.resize(numberOfSuccessors);

        int row;
        double minF = 999999999999;
        for (int i=0; i<numberOfSuccessors; i++)
        {
            double f;
            nodeSuccessors[i] = (edgeSuccessors[i])->getTarget();
            f = heuristic->evaluateHeuristic(nodeSuccessors[i],edgeSuccessors[i]);
            if (f < minF)
            {
                minF = f;
                row  = i;
            }

            if (!isNodeInExploredSetOrFrontier(nodeSuccessors[i]))
                addNodeToFrontier(nodeSuccessors[i],f);


        }

        currentNode = frontier.nodes[numberOfNodesInFrontier];
    }

    // Store Solution
}

void AStarGraphSearch::sortPriorityQueue()
{
}

std::vector <Node*> AStarGraphSearch::getExploredSet()
{
    return exploredSet;
}
