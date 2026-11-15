
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

int parent[100];

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int main()
{
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;

    cout << "Enter u, v and weight:\n";
    for (int i = 0; i < E; i++)
    {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), compare);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int cost = 0;

    cout << "Edges in MST:\n";

    for (Edge e : edges)
    {
        int a = find(e.u);
        int b = find(e.v);

        if (a != b)
        {
            parent[a] = b;
            cout << e.u << " - " << e.v
                 << " : " << e.w << endl;

            cost += e.w;
        }
    }

    cout << "Minimum Cost: " << cost;

    return 0;
}

