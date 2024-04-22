#include <iostream>
#include <vector>

using namespace std;

void recursive(int n, int m, vector<int>& memo, vector<bool>& visited,
               int depth) {
    if (depth >= m) {
        for (int i = 0; i < m - 1; i++) {
            cout << memo[i] << ' ';
        }
        cout << memo[m - 1] << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        memo[depth] = i;

        recursive(n, m, memo, visited, depth + 1);

        visited[i] = false;
        memo[depth] = -1;
    }
}

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int m, n;  // [1, 8]
    cin >> n >> m;

    vector<int> memo(n, -1);
    vector<bool> visited(n, false);

    recursive(n, m, memo, visited, 0);
}