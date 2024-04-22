// BFS
// string -> arr

// input: 2 <= n, m <= 100, board
// output: distance from (0, 0) to (n-1, m-1)

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

    vector<vector<int>> board(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;

        for (int j = 0; j < m; j++) {
            auto c = line[j];
            if (c == '1') {
                board[i][j] = 1;
            }
        }
    }

    vector<vector<int>> distance(n, vector<int>(m, 0));
    queue<pair_int> q;

    q.push({0, 0});
    distance[0][0] = 1;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto [dx, dy] : direct) {
            auto nx = cx + dx;
            auto ny = cy + dy;

            bool on_board = 0 <= nx && nx < n && 0 <= ny && ny < m;
            if (!on_board || board[nx][ny] != 1 || distance[nx][ny] != 0)
                continue;

            distance[nx][ny] = distance[cx][cy] + 1;
            q.push({nx, ny});
        }
    }

    cout << distance[n - 1][m - 1] << '\n';
}