#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pair_int;

int main(void)
{
    int n, m;
    cin >> m >> n;

    vector<vector<int>> box(n, vector(m, 0));
    queue<pair_int> q;

    int im_cnt = 0;
    int last_day = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 0)
                im_cnt++;

            if (box[i][j] == 1)
                q.push({i, j});
        }
    }

    int direct[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto d : direct)
        {
            int nx = cx + d[0];
            int ny = cy + d[1];

            if (0 <= nx && nx < n && 0 <= ny && ny < m && box[nx][ny] == 0)
            {
                box[nx][ny] = box[cx][cy] + 1;
                last_day = box[nx][ny] - 1;
                im_cnt--;
                q.push({nx, ny});
            }
        }
    }

    if (im_cnt)
        cout << "-1" << '\n';
    else
        cout << last_day << '\n';
}
