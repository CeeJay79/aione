#ifndef HEURISTIC_HPP
#define HEURISTIC_HPP

#include "node.hpp"
#include "edge.hpp"

class Heuristic
{
public:
    Heuristic();

    double evaluateHeuristic(Node*,Edge*);
};

#endif // HEURISTIC_HPP
