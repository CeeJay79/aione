#ifndef HEURISTIC_HPP
#define HEURISTIC_HPP

#include "node.hpp"
#include "edge.hpp"

class Heuristic
{
public:
    Heuristic();

    void initGoal(Node*);
    double evaluateHeuristic(Node*,Edge*);

private:
    Node* goalNode;
};

#endif // HEURISTIC_HPP
