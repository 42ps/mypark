#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pair_int;

const pair_int direct[4] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

void tour(const vector<string>& board, vector<vector<bool>>& visited,
          pair_int start) {
    int n = board.size();
    auto [sx, sy] = start;
    char color = board[sx][sy];

    queue<pair_int> q;
    visited[sx][sy] = true;
    q.push(start);

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto [dx, dy] : direct) {
            auto nx = cx + dx;
            auto ny = cy + dy;

            bool on_board = (0 <= nx && nx < n) && (0 <= ny && ny < n);
            if (!on_board || board[nx][ny] != color || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int nr_section(const vector<string>& board) {
    int n = board.size();
    int cnt = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;

            tour(board, visited, {i, j});
            cnt++;
        }
    }
    return cnt;
}

int main(void) {
    int n = 0;  // 1<= n <= 100

    cin >> n;

    vector<string> board;

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        board.push_back(x);
    }

    cout << nr_section(board) << ' ';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'R') board[i][j] = 'G';
        }
    }

    cout << nr_section(board) << '\n';
}