#ifndef ASTARGRAPHSEARCH_HPP
#define ASTARGRAPHSEARCH_HPP

#include <vector>
#include "search.hpp"
#include "feeder.hpp"

class AStarGraphSearch : public Search
{
public:
    AStarGraphSearch(Feeder*);

    void initHeuristic();
    void runSearch();

    struct nodeAndCost getExploredSet();

protected:

    void sortPriorityQueue();
};

#endif // ASTARGRAPHSEARCH_HPP
