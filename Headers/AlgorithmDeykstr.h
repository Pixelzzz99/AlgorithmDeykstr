#pragma once
#include <vector>

class AlgorithmDeykstr
{
private:
    int countOfVertex_N;
    int countOfEdges_M;
    int startVertex_S;
public:
    const long long INFINITY = 1e18;
    
    int getCountOfVertex_N();
    void setCountOfVertex_N(int CountOfVertex_N);

    int getCountOfEdges_M();
    void setCountOfEdges_M(int CountOfEdges_M);

    int getStartVertex_S();
    void setStartVertex_S(int StartVertex_S);

    virtual std::vector<long long> solve() = 0;
    ~AlgorithmDeykstr() {}
};