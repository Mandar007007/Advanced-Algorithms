#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <climits>

using namespace std;
#define n 6

bool bfs(vector<vector<int>> &rgraph, int s, int t, vector<int> &parent)
{
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (vis[v] == 0 && rgraph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[t] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                vis[v] = 1;
            }
        }
    }
    // If there are no possible way or path to go to s to t
    return false;
}

// Ford fulkerson implementation where s is source and t is sink
int ford_fulkerson(vector<vector<int>> &graph, int s, int t)
{
    // Make residual graph
    vector<vector<int>> rgraph(graph);

    // Make parent vector which will initialize in the bfs
    vector<int> parent(n, 0);
    int max_flow = 0;

    while (bfs(rgraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    // Graph which is stored in matrix format
    vector<vector<int>> graph({
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0},
    });

    // Finding the max flow of the graph using ford fulkerson
    cout << "Max Flow: " << ford_fulkerson(graph, 0, 5);

    return 0;
}
