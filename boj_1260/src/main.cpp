#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& adj_list, vector<bool>& visited, int node,
         int depth) {
    if (depth != 0) cout << ' ';
    cout << node + 1;
    visited[node] = true;

    for (auto n : adj_list[node]) {
        if (!visited[n]) {
            dfs(adj_list, visited, n, depth + 1);
        }
    }
}

void bfs(const vector<vector<int>>& adj_list, vector<bool>& visited, int node) {
    queue<int> q;

    q.push(node);
    cout << node + 1;
    visited[node] = true;

    while (!q.empty()) {
        auto c = q.front();
        q.pop();

        for (auto n : adj_list[c]) {
            if (!visited[n]) {
                visited[n] = true;

                cout << ' ' << n + 1;
                q.push(n);
            }
        }
    }
}

int main(void) {
    int n, m, s;
    cin >> n >> m >> s;

    s -= 1;

    vector<vector<int>> adj_list(n, vector<int>());
    vector<bool> visited(n, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        x -= 1;
        y -= 1;

        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if (!adj_list[i].empty()) sort(adj_list[i].begin(), adj_list[i].end());
    }

    dfs(adj_list, visited, s, 0);
    cout << '\n';

    visited.assign(n, false);

    bfs(adj_list, visited, s);
    cout << '\n';
}