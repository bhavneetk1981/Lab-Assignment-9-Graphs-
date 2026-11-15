
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (cost > dist[x][y])
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m &&
                ny >= 0 && ny < n)
            {
                int newCost = cost + grid[nx][ny];

                if (newCost < dist[nx][ny])
                {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }

    cout << "Minimum Cost: " << dist[m-1][n-1];

    return 0;
}


