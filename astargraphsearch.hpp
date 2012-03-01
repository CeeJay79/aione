#ifndef ASTARGRAPHSEARCH_HPP
#define ASTARGRAPHSEARCH_HPP

#include <vector>
#include "search.hpp"
#include "feeder.hpp"

#include <iostream>
#include <stdlib.h>

class AStarGraphSearch : public Search
{
public:
    AStarGraphSearch(Feeder*);

    Node* runSearch();

    std::vector <Node*> getExploredSet();

protected:

    void sortPriorityQueue();
};

#endif // ASTARGRAPHSEARCH_HPP
