// BFS

// input: 0<= N <= 25, board
// output: n_grp, n_house[]

#include <algorithm>
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

int tour_board(const vector<vector<int>>& board, vector<vector<bool>>& visited,
               pair_int start) {
    int n = board.size();
    int n_house = 0;
    queue<pair_int> q;

    visited[start.first][start.second] = true;
    q.push(start);
    n_house++;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto [dx, dy] : direct) {
            auto nx = cx + dx;
            auto ny = cy + dy;

            bool on_board = 0 <= nx && nx < n && 0 <= ny && ny < n;
            if (!on_board || board[nx][ny] == 0 || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
            n_house++;
        }
    }
    return n_house;
}

int main(void) {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;

        for (int j = 0; j < n; j++) {
            board[i][j] = line[j] - '0';
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int n_grp = 0;
    vector<int> n_houses;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 || visited[i][j]) continue;

            int x = tour_board(board, visited, {i, j});
            n_grp++;
            n_houses.push_back(x);
        }
    }

    sort(n_houses.begin(), n_houses.end());

    cout << n_grp << '\n';

    for (auto n : n_houses) {
        cout << n << '\n';
    }
}