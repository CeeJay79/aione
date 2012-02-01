#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <vector>
#include "feeder.hpp"
#include "heuristic.hpp"
#include "node.hpp"
#include "edge.hpp"

struct
{
    std::vector <Node*>  nodes;
    std::vector <double> costs;
} frontier;

class Search
{
public:

    Search(Feeder*);

    void initInitNode(int);
    void initGoalNode(int);
    void initHeuristic(Heuristic*);

    virtual void runSearch() = 0;

    std::vector<Node*> getFrontier();
    std::vector<Node*> getExploredSet();

protected:

    bool  goalTest(Node*);
    Node* popFrontier();
    void  addNodeToFrontier(Node*);
    void  addNodeToExploredSet(Node*);
    virtual void sortPriorityQueue() = 0;

    Feeder* feeder;
    int initNodeID;
    int goalNodeID;
    Heuristic* heuristic;
    int numberOfNodesInFrontier;
    int numberOfNodesInExploredSet;
    std::vector <Node*> exploredSet;
};

#endif // SEARCH_HPP
