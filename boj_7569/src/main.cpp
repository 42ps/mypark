#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int, int> tuple_int;

int direct[6][3] = {
    {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1},
};

int main(void) {
    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> box(H,
                                    vector<vector<int>>(N, vector<int>(M, 0)));

    queue<tuple_int> q;

    int nr_immurture = 0;
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                int x;
                cin >> x;
                box[h][n][m] = x;
                if (x == 0) nr_immurture++;
                if (x == 1) q.push({h, n, m});
            }
        }
    }

    int ans = 0;
    while (!q.empty()) {
        auto [ch, cx, cy] = q.front();
        q.pop();

        for (auto [dh, dx, dy] : direct) {
            auto nh = ch + dh;
            auto nx = cx + dx;
            auto ny = cy + dy;

            bool in_box =
                0 <= nh && nh < H && 0 <= nx && nx < N && 0 <= ny && ny < M;
            if (!in_box || box[nh][nx][ny] != 0) continue;

            nr_immurture--;
            ans = box[ch][cx][cy];
            box[nh][nx][ny] = ans + 1;
            q.push({nh, nx, ny});
        }
    }

    if (nr_immurture)
        cout << "-1" << '\n';
    else
        cout << ans << '\n';
}