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

    addNodeToFrontier(initialNode);

    while (true)
    {
        currentNode = popFrontier();

        goalFound = goalTest(currentNode);
        if (goalFound)
        {
            break;
        }

        addNodeToExploredSet(currentNode);

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
        }

        addNodeToFrontier(nodeSuccessors[row]);
        for (int i=0; i<numberOfSuccessors; i++)
        {
            if (i != row)
                exploredSet.push_back(nodeSuccessors[i]);
        }

        currentNode = frontier[1];
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
