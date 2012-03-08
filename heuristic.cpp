#include "heuristic.hpp"

Heuristic::Heuristic()
{
}

void Heuristic::initGoal(Node* inNode)
{
    goalNode = inNode;
}

double Heuristic::evaluateHeuristic(double g, Node* inNodePrime)
{
    double f;
    double h;
    h = 0; // use goal node and inNodePrime here

    f = g + h;
    return f;
}
