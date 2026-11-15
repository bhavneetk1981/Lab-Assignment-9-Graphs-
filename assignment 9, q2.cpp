
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int x : adj[node])
    {
        if (!visited[x])
        {
            DFS(x, adj, visited);
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter edges:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);

    cout << "DFS Traversal: ";
    DFS(0, adj, visited);

    return 0;
}


