#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pair_int;

int calc_kb(const vector<vector<int>>& adj_list, int who) {
    queue<pair_int> q;
    vector<bool> visited(adj_list.size(), false);
    int sum = 0;

    q.push({who, 0});
    visited[who] = true;

    while (!q.empty()) {
        auto [cx, cnt] = q.front();
        q.pop();

        for (auto nx : adj_list[cx]) {
            if (visited[nx]) continue;
            sum += cnt;
            q.push({nx, cnt + 1});
            visited[nx] = true;
        }
    }
    return sum;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    int min_kb = INT32_MAX;
    int person = 0;

    for (int i = 0; i < n; i++) {
        int kb = calc_kb(adj_list, i);

        if (kb < min_kb) {
            min_kb = kb;
            person = i;
        }
    }

    cout << person + 1 << '\n';
}
