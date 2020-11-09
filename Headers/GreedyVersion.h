#pragma once
#include "AlgorithmDeykstr.h"
#include "Edge.h"
#include "RandomTasks.h"
#include <set>
#include <utility>
#include <iostream>
class GreedyVersion : public AlgorithmDeykstr
{
private:
    std::vector<std::vector<Edge>> graph;
    void resizeVectorGraph(int size);
    void setGraph(std::vector<std::pair<std::pair<int, int>, int>> graph);

public:
    GreedyVersion(RandomTasks);
    GreedyVersion(int n, int m, int s, std::vector<std::pair<std::pair<int, int>, int>> graph);
    ~GreedyVersion(){};
    
    std::vector<long long> solve() override;
    void print(int countOfVertex, int startVertex, std::vector<long long> Deykstr);
};