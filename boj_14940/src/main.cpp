#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pair_int;

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m, 0)), dist(n, vector<int>(m, -1));
    pair_int start;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 2)
            {
                start = {i, j};
                dist[i][j] = 0;
            }

            if (board[i][j] == 0)
            {
                dist[i][j] = 0;
            }
        }
    }

    int direct[4][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
    };

    queue<pair_int> q;

    q.push(start);
    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto d : direct)
        {
            int nx = cx + d[0];
            int ny = cy + d[1];

            if (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] == 1 && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (auto line : dist)
    {
        cout << line[0];
        for (int j = 1; j < m; j++)
        {
            cout << ' ' << line[j];
        }
        cout << '\n';
    }
}