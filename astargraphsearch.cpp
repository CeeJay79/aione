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

    // Initialize Variables
    goalFound = 0;
    initialNode = feeder->getNode(initNodeID);
    initialNode->setCurrentCost(0);

    Node* finalNode = feeder->getNode(goalNodeID);
    double k = heuristic->evaluateHeuristic(0,finalNode);
    addNodeToFrontier(initialNode,k);

    while (numberOfNodesInFrontier > 0)
    {
        // Declare some variables
        std::vector <Node*> nodeSuccessors;
        std::vector <Edge*> edgeSuccessors;

        currentNode = popFrontier();
        currentNode->setExplored(1);


#if GUI_DISPLAY ==1
        // Notification for Simulator
        notifyObservers(currentNode->getNodeID(),NODE_UPDATE);
//        sleep(1);
//        system("read -p \"Press a key to continue...\" -n 1 -s");
        // -----------------------------------------------------------
#endif



        goalFound = goalTest(currentNode);
        if (goalFound)
        {
            break;
        }

        addNodeToExploredSet(currentNode,0/*The 0 is not important for explored set*/);

        feeder->getSuccessors(currentNode,&edgeSuccessors);
        int numberOfSuccessors = edgeSuccessors.size();
        nodeSuccessors.resize(numberOfSuccessors);

        for (int i=0; i<numberOfSuccessors; i++)
        {
            double g;
            double f;

            nodeSuccessors[i] = edgeSuccessors[i]->getTarget();

            g = currentNode->getCurrentCost() + edgeSuccessors[i]->getCost();
            f = heuristic->evaluateHeuristic(g,nodeSuccessors[i]);



            // Notification for Simulator
            notifyObservers(edgeSuccessors[i]->getEdgeID(),EDGE_UPDATE);
            // -----------------------------------------------------------




            if (isNodeInExploredSet(nodeSuccessors[i]) == 0)
            {
                int jj = isNodeInFrontier(nodeSuccessors[i]);
                if (jj == 0)
                {
                    nodeSuccessors[i]->setCurrentCost(g);
                    nodeSuccessors[i]->setHeuristicValue(f);

                    nodeSuccessors[i]->setParent(currentNode);
                    addNodeToFrontier(nodeSuccessors[i],f);
                }
                else if (jj > 0)
                {
                    nodeSuccessors[i]->setCurrentCost(g);
                    nodeSuccessors[i]->setHeuristicValue(f);

                    nodeSuccessors[i]->setParent(currentNode);
                    frontier.nodes.erase(frontier.nodes.begin() + jj);
                    frontier.costs.erase(frontier.costs.begin() + jj);
                    numberOfNodesInFrontier--;
                    addNodeToFrontier(nodeSuccessors[i],f);
                }
            }
        }
    }

    if (goalFound)
        return currentNode;
    else
        return NULL;
}

void AStarGraphSearch::sortPriorityQueue()
{
}

std::vector <Node*> AStarGraphSearch::getExploredSet()
{
    return exploredSet.nodes;
}
