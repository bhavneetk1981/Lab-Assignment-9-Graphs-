
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int N, E, K;
    cin >> N >> E;

    vector<pair<int, int>> adj[N + 1];

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    cin >> K;

    vector<int> dist(N + 1, INT_MAX);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[K] = 0;
    pq.push({0, K});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << -1;
            return 0;
        }

        ans = max(ans, dist[i]);
    }

    cout << "Network Delay Time: " << ans;

    return 0;
}

