#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(const vector<int>& jump) {
    vector<int> count(101, 0);
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int src = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int cnt = count[src] + 1;
            int dst = src + i;
            dst = jump[dst] ? jump[dst] : dst;

            if (count[dst]) continue;
            if (dst == 100) return cnt;

            count[dst] = cnt;
            q.push(dst);
        }
    }
    return -1;
}

int main(void) {
    int n, m;

    cin >> n >> m;

    vector<int> jump(101, 0);

    for (int i = 0; i < n + m; i++) {
        int x, y;
        cin >> x >> y;
        jump[x] = y;
    }

    cout << bfs(jump) << '\n';
}