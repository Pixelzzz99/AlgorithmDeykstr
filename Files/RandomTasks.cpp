#include "RandomTasks.h"

RandomTasks::RandomTasks()
{
    srand(time(nullptr));
    n = Randomizator(1, 7);
    generateGraph();
    s = Randomizator(1, n);
}

int RandomTasks::Randomizator(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void RandomTasks::generateGraph()
{
    std::vector<int> v = {1};
    int id_v = 2;
    int count_d = n - 1;
    while (count_d > 0)
    {
        int position = Randomizator(0, v.size() - 1);
        int now_v = v[position];
        v.push_back(id_v);
        ;
        int length = Randomizator(1, 10);
        graph.push_back({{now_v, id_v}, length});
        mp[{now_v, id_v}] = mp[{id_v, now_v}] = 1;
        id_v++;
        count_d--;
    }

    m = n - 1;
    int it = Randomizator(0, 5);
    while (it--)
    {
        int pos1 = Randomizator(0, v.size() - 1);
        int pos2 = Randomizator(0, v.size() - 1);
        if (pos1 == pos2) continue;
        int v1 = v[pos1], v2 = v[pos2];
        if (mp.count({v1, v2})) continue;
        int len = Randomizator(1, 10);
        mp[{v1, v2}] = mp[{v2, v1}] = 1;
        graph.push_back({{v1, v2}, len});
        m++;
    }
}

int RandomTasks::get_N()
{
    return n;
}

int RandomTasks::get_M()
{
    return m;
}

int RandomTasks::get_S()
{
    return s;
}

std::vector<std::pair<std::pair<int, int>, int>> RandomTasks::get_Graph()
{
    return graph;
}