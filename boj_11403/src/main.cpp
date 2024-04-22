#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> bfs(int start, const vector<vector<int>>& adj_list) {
    int n = adj_list.size();
    vector<int> memo(n, 0);
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto n : adj_list[x]) {
            if (visited[n]) {
                if (n == start) memo[n] = 1;
                continue;
            }

            visited[n] = true;
            memo[n] = 1;
            q.push(n);
        }
    }

    return memo;
}

int main(void) {
    int n;

    cin >> n;

    vector<vector<int>> adj_list(n, vector<int>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x) {
                adj_list[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        auto memo = bfs(i, adj_list);

        cout << memo[0];
        for (int j = 1; j < n; j += 1) {
            cout << ' ' << memo[j];
        }
        cout << '\n';
    }
}