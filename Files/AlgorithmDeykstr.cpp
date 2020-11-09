#include "AlgorithmDeykstr.h"

int AlgorithmDeykstr::getCountOfVertex_N()
{
    return this->countOfVertex_N;
}

int AlgorithmDeykstr::getCountOfEdges_M()
{
    return this->countOfEdges_M;
}

int AlgorithmDeykstr::getStartVertex_S()
{
    return this->startVertex_S;
}

void AlgorithmDeykstr::setCountOfVertex_N(int CountOfVertex_N)
{
    this->countOfVertex_N = CountOfVertex_N;
}

void AlgorithmDeykstr::setCountOfEdges_M(int CountOfEdges_M)
{
    this->countOfEdges_M = CountOfEdges_M;
}

void AlgorithmDeykstr::setStartVertex_S(int StartVertex_S)
{
    this->startVertex_S = StartVertex_S;
}