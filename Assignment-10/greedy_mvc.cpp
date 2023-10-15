#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Graph
{
    int V;
    vector<set<int>> adjList;

public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int u, int v)
    {
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    void removeEdge(int u, int v)
    {
        adjList[u].erase(v);
        adjList[v].erase(u);
    }

    void greedyMVC()
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                for (auto x : adjList[i])
                {
                    if (!visited[x])
                    {
                        visited[i] = true;
                        visited[x] = true;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (visited[i])
            {
                cout << i << " ";
            }
        }
    }
};

int main()
{
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.greedyMVC();
    return 0;
}

// output
// 0 1 3 4