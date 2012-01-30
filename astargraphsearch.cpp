#include "astargraphsearch.hpp"

AStarGraphSearch::AStarGraphSearch(Feeder* inFeeder)
{
    feeder = inFeeder;
}

void AStarGraphSearch::initHeuristic()
{
}

void AStarGraphSearch::runSearch()
{
    bool  goalFound(0);
    Node* cNode;

    std::vector <Node*> nodeSuccessors;
    std::vector <Edge*> edgeSuccessors;

    while (true)
    {
        bool test = goalTest(cNode);
        if (test == 1)
        {
            goalFound = 1;
            break;
        }

//        feeder->getSuccessors(cNode,&nodeSuccessors,&edgeSuccessors);

        int numberOfSuccessors = edgeSuccessors.size();

        int row;
        double minF = 999999999999;

        for (int i=0; i<numberOfSuccessors; i++)
        {
            double f;
            //f = heuristic->evaluateHeuristic(nodeSuccessors[i],edgeSuccessors[i]);
            if (f < minF)
            {
                minF = f;
                row = i;
            }
        }

        addNodeToFrontier(nodeSuccessors[row]);
        for (int i=0; i<numberOfSuccessors; i++)
        {
            if (i != row)
                exploredSet.push_back(nodeSuccessors[i]);
        }

        cNode = frontier[1];
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
