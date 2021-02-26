#include "FirstVersion.h"

FirstVersion::FirstVersion(RandomTasks *Task)
{
    setCountOfVertex_N(Task->get_N());
    setCountOfEdges_M(Task->get_M());
    setStartVertex_S(Task->get_S());
    resizeVectorGraph(getCountOfVertex_N());
    setGraph(Task->get_Graph());
}

FirstVersion::FirstVersion(int n, int m, int s, std::vector<std::pair<std::pair<int, int>, int>> graph)
{
    setCountOfVertex_N(n);
    setCountOfEdges_M(m);
    setStartVertex_S(s);
    resizeVectorGraph(getCountOfVertex_N());
    setGraph(graph);
}

void FirstVersion::resizeVectorGraph(int size)
{
    graph.resize(size + 1);
    for (int i = 0; i < size + 1; i++)
    {
        graph[i].resize(size + 1);
    }
    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < size + 1; j++)
        {
            graph[i][j] = -1;
        }
    }
    _memory = sizeof(graph) + ((size*size) * sizeof(int)) ;
}

int FirstVersion::getMem()
{
    return _memory;
}

void FirstVersion::setGraph(std::vector<std::pair<std::pair<int, int>, int>> graph)
{

    for (int i = 0; i < getCountOfEdges_M(); i++)
    {
        int v = graph[i].first.first;
        int u = graph[i].first.second;
        int length = graph[i].second;
        this->graph[u][v] = length;
        this->graph[v][u] = length;
    }
}

std::vector<long long> FirstVersion::solve()
{
    int startVertex = getStartVertex_S();
    std::vector<long long> Deykstr(getCountOfVertex_N() + 1, INFINITY);
    Deykstr[startVertex] = 0;
    std::set<std::pair<int, int>> st;

    st.insert({Deykstr[startVertex], startVertex});

    while (!st.empty())
    {
        int vertex = st.begin()->second;
        st.erase(st.begin());
        for (int i = 1; i <= getCountOfVertex_N(); i++)
        {
            if (graph[vertex][i] == -1)
                continue;
            int to = i;
            int length = graph[vertex][i];
            if (Deykstr[vertex] + length < Deykstr[to])
            {
                st.erase({Deykstr[to], to});
                Deykstr[to] = Deykstr[vertex] + length;
                st.insert({Deykstr[to], to});
            }
        }
    }
    return Deykstr;
}

void FirstVersion::print(int countOfVertex, int startVertex, std::vector<long long> Deykstr)
{
    for (int i = 1; i <= countOfVertex; i++)
    {
        std::cout << "DIST FROM " << startVertex << " TO " << i << " is " << Deykstr[i] << std::endl;
    }
}