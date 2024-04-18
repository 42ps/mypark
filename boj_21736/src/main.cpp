#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pair_int;

int direct[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> campus(n, vector<char>(m, ' '));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    pair_int start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> campus[i][j];
            if (campus[i][j] == 'I') {
                start = {i, j};
            }
        }
    }

    int person_count = 0;
    queue<pair_int> q;
    visited[start.first][start.second] = true;
    q.push(start);

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto [dx, dy] : direct) {
            auto nx = cx + dx;
            auto ny = cy + dy;

            bool in_campus = 0 <= nx && nx < n && 0 <= ny && ny < m;

            if (!in_campus || visited[nx][ny] || campus[nx][ny] == 'X')
                continue;

            if (campus[nx][ny] == 'P') person_count++;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    if (person_count) {
        cout << person_count << '\n';
    } else {
        cout << "TT" << '\n';
    }
}
