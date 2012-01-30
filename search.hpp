#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <vector>
#include "feeder.hpp"
#include "heuristic.hpp"
#include "node.hpp"
#include "edge.hpp"

class Search
{
public:
    Search();

    void initInitNode(int);
    void initGoalNode(int);
    void initHeuristic(Heuristic*);

    virtual void runSearch() = 0;
    void addNodeToFrontier(Node*);
    void addNodeToExploredSet(Node*);

    std::vector<Node*> getFrontier();
    std::vector<Node*> getExploredSet();

protected:

    bool goalTest(Node*);
    virtual void sortPriorityQueue() = 0;

    Feeder* feeder;
    int initNodeID;
    int goalNodeID;
    Heuristic* heuristic;
    int numberOfNodesInFrontier;
    int numberOfNodesInExploredSet;
    std::vector <Node*> frontier;
    std::vector <Node*> exploredSet;
};

#endif // SEARCH_HPP
