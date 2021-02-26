#pragma once
#include <utility>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>

class RandomTasks
{
private:
    int n_;
    int m_;
    int s_;
    std::vector<std::pair<std::pair<int, int>, int>> graph;
    
    std::map<std::pair <int, int>, bool> mp;
    int Randomizator(int min, int max);
    void generateGraph();
public:
    int get_N();
    int get_M();
    int get_S();
    std::vector<std::pair<std::pair<int, int>, int>> get_Graph();
    
    RandomTasks();
    RandomTasks(int, int);
    ~RandomTasks()=default;
};