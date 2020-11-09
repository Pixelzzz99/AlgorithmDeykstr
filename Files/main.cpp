#include <iostream>
#include "GreedyVersion.h"
#include "RandomTasks.h"



int main()
{
    RandomTasks task1;
    GreedyVersion solve1(task1);
    std::vector<long long> deykstr = solve1.solve();
    std::vector<std::pair<std::pair<int, int>, int > > graphBefore = task1.get_Graph();
    
    std::cout<<"Count_vertex  and  count_edge "<<solve1.getCountOfVertex_N()<<" "<<solve1.getCountOfEdges_M()<<std::endl;
    for (auto x: graphBefore)
    {
        std::cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<std::endl;
    }
    
    solve1.print(solve1.getCountOfVertex_N(), solve1.getStartVertex_S(), deykstr);
    system("pause>nul");
    return 0;
}