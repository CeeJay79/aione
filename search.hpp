#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <vector>
#include "feeder.hpp"
#include "heuristic.hpp"
#include "node.hpp"
#include "edge.hpp"
#include "observable.hpp"

struct nodeAndCost
{
    std::vector <Node*>  nodes;
    std::vector <double> costs;
};

class Search : public Observable
{
public:

    Search(Feeder*);

    void initInitNode(int);
    void initGoalNode(int);
    void initHeuristic(Heuristic*);

    virtual Node* runSearch() = 0;

    std::vector<Node*> getFrontier();
    std::vector<Node*> getExploredSet();

protected:

    bool  goalTest(Node*);
    int   isNodeInFrontier(Node*);
    int   isNodeInExploredSet(Node*);
    Node* popFrontier();
    void  addNodeToFrontier(Node*,double);
    void  addNodeToExploredSet(Node*,double);
    virtual void sortPriorityQueue() = 0;

    Feeder* feeder;
    int initNodeID;
    int goalNodeID;
    Heuristic* heuristic;
    int numberOfNodesInFrontier;
    int numberOfNodesInExploredSet;
    struct nodeAndCost frontier;
    struct nodeAndCost exploredSet;
};

#endif // SEARCH_HPP
