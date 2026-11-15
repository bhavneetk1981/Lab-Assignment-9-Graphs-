
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], bool visited[])
{
    visited[node] = true;

    for (int x : adj[node])
    {
        if (!visited[x])
            DFS(x, adj, visited);
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool visited[V] = {false};
    int count = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS(i, adj, visited);
            count++;
        }
    }

    cout << "Number of Connected Components: " << count;

    return 0;
}

