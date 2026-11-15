
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[100][100];

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];
    }

    int key[100], parent[100];
    bool visited[100] = {false};

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < V; count++)
    {
        int u = -1;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;
        }

        if (u == -1 || key[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int cost = 0;

    cout << "Edges in MST:\n";

    for (int i = 1; i < V; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << " - "
                 << i << " : " << key[i] << endl;
            cost += key[i];
        }
    }

    cout << "Minimum Cost: " << cost;

    return 0;
}

