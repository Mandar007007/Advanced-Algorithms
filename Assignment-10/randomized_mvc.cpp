#include <bits/stdc++.h>

using namespace std;

void remove_edges(vector<vector<int>> &graph, int n) {
    auto it = graph.begin();
    while(it != graph.end()) {
        if((*it)[0] == n || (*it)[1] == n) {
            it = graph.erase(it);
        }
        else {
            it++;
        }
    }
}

vector<int> mvc(vector<vector<int>> &graph) {
    vector<int> ans;
    srand(time(0));
    while(!graph.empty()) {
        int i = rand() % 5;
        int u = graph[i][0];
        int v = graph[i][1];
        ans.push_back(u);
        ans.push_back(v);
        remove_edges(graph,u);
        remove_edges(graph,v);
    }
    return ans;
}

int main()
{
    set<int> ans;
    vector<vector<int>> graph {
        {1,2},
        {2,3},
        {2,4},
        {3,5},
        {3,6},
        {4,5},
    };
    int n = graph.size();
    vector<int> s= mvc(graph);
    for(auto x: s) {
        cout << x << " ";
    }
    
    return 0;
}
