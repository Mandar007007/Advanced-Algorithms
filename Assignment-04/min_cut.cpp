#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

// Function to select a random edge from the graph
pair<int, int> random_edge_selection(vector<vector<int>> &graph)
{
    // Get the number of vertices in the graph
    int num_vertices = graph.size();

    // Create a random number generator
    default_random_engine generator(time(0));
    uniform_int_distribution<int> distribution(0, num_vertices - 1);

    // Select a random vertex (index) from the graph
    int vertex = distribution(generator);

    // Find a random neighbor of the selected vertex
    int neighbor;
    do
    {
        neighbor = distribution(generator);
    } while (neighbor == vertex || graph[vertex][neighbor] == 0);

    // Return the selected edge (vertex and neighbor)
    return make_pair(vertex, neighbor);
}

// Function to perform one iteration of the Karger's algorithm
int karger_min_cut(vector<vector<int>> &graph)
{
    int num_vertices = graph.size();

    // Keep merging vertices until only two vertices are left
    while (num_vertices > 2)
    {
        // Randomly select an edge from the graph
        pair<int, int> edge = random_edge_selection(graph);

        // Merge the two selected vertices (contract the edge)
        int u = edge.first;
        int v = edge.second;
        for (int i = 0; i < num_vertices; i++)
        {
            // Merge v into u
            graph[u][i] += graph[v][i];
            graph[i][u] += graph[i][v];
        }

        // "Remove" the merged vertex (mark it as not connected)
        for (int i = 0; i < num_vertices; i++)
        {
            graph[v][i] = 0;
            graph[i][v] = 0;
        }

        // Reduce the number of vertices in the graph
        num_vertices--;
    }

    // Find and return the minimum cut value (the number of edges between the two remaining vertices)
    int min_cut = 0;
    for (int i = 0; i < graph[0].size(); i++)
    {
        min_cut += graph[0][i];
    }
    return min_cut;
}

int main()
{
    // Graph which is stored in matrix format
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}};

    cout << "Minimum Cut: " << karger_min_cut(graph) << endl;

    return 0;
}
