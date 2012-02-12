#ifndef HEURISTIC_HPP
#define HEURISTIC_HPP

#include "node.hpp"
#include "edge.hpp"

class Heuristic
{
public:
    Heuristic();

    void initGoal(Node*);
    double evaluateHeuristic(double,Node*);
//    void evaluateHeuristic(Node*,Edge*,Node*);

private:
    Node* goalNode;
    double g;
    double h;
};

#endif // HEURISTIC_HPP
