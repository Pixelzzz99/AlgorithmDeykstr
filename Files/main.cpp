#include <iostream>
#include "AlgorithmDeykstr.h"
#include "FirstVersion.h"
#include "GreedyVersion.h"
#include "RandomTasks.h"
#include <fstream>

RandomTasks *task1 = new RandomTasks();

void testFirstVersion()
{
    FirstVersion *solve1 = new FirstVersion(task1);

    unsigned int time_clock = clock();
    std::vector<long long> deykstr = solve1->solve();
    double time = (double)(clock() - time_clock) / CLOCKS_PER_SEC;

    std::vector<std::pair<std::pair<int, int>, int>> graphBefore = task1->get_Graph();

    std::cout << "Count_vertex  and  count_edge " << solve1->getCountOfVertex_N() << " " << solve1->getCountOfEdges_M() << std::endl;
    for (auto x : graphBefore)
    {
        std::cout << x.first.first << " " << x.first.second << " " << x.second << std::endl;
    }

    solve1->print(solve1->getCountOfVertex_N(), solve1->getStartVertex_S(), deykstr);
    std::cout << "Time: " << time << std::endl;
    delete solve1;
}

void testGreedyVersion()
{
    GreedyVersion *solve1 = new GreedyVersion(task1);

    unsigned int time_clock = clock();
    std::vector<long long> deykstr = solve1->solve();
    double time = (double)(clock() - time_clock) / CLOCKS_PER_SEC;

    std::vector<std::pair<std::pair<int, int>, int>> graphBefore = task1->get_Graph();

    std::cout << "Count_vertex  and  count_edge " << solve1->getCountOfVertex_N() << " " << solve1->getCountOfEdges_M() << std::endl;
    for (auto x : graphBefore)
    {
        std::cout << x.first.first << " " << x.first.second << " " << x.second << std::endl;
    }

    solve1->print(solve1->getCountOfVertex_N(), solve1->getStartVertex_S(), deykstr);
    std::cout << "Time: " << time << std::endl;
    delete solve1;
}

void ExcelTest()
{
    std::ofstream Table;
    Table.open("D:\\projects\\AlgorithmDeykstr\\Table\\Table.csv");
    if (Table.is_open())
    {
        Table << "N ;"
              << "Time First Version ;"
              << "Time Second Version ;"
              << "Result Compare ;"
              << "Memory First ;"
              << "Memory Second; " << std::endl;
        int step = 1000;
        for (int i = 1000; i <= 100000; i += step)
        {
            RandomTasks *task2 = new RandomTasks(i, 2);
            Table << i << ";";
            std::cout << i << std::endl;
            GreedyVersion *solve2 = new GreedyVersion(task2);

            unsigned int time_clock2 = clock();
            std::vector<long long> deykstr2 = solve2->solve();
            double time2 = (double)(clock() - time_clock2) / CLOCKS_PER_SEC;
            int memory2 = solve2->getMem();

            std::vector<long long> deykstr1;
            double time1;
            int memory1;
            if (i < 10000)
            {
                FirstVersion *solve1 = new FirstVersion(task2);
                unsigned int time_clock1 = clock();
                deykstr1 = solve1->solve();
                time1 = (double)(clock() - time_clock1) / CLOCKS_PER_SEC;
                memory1 = solve1->getMem();
                Table << time1 << ";";
                delete solve1;
            }
            else
            {
                step = 10000;
                Table << ";";
            }
            std::string compare = deykstr1 == deykstr2 ? "True" : "False";

            std::cout << "Time1: " << time1 << "\t"
                      << "Time2: " << time2
                      << "\t" << memory1 << "\t" << memory2 << std::endl;
            Table << time2 << ";" << compare << ";" << memory1 << ";" << memory2 << std::endl;
            delete solve2;
            delete task2;
        }
    }
    std::cout << "Test Finisted" << std::endl;
}

int main()
{
    ExcelTest();
    //testFirstVersion();
    //testGreedyVersion();
    //delete task1;
    system("pause>nul");
    return 0;
}