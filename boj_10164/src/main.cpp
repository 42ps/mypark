#include <iostream>

using namespace std;

typedef pair<int, int> pair_int;
const int l_max = 15;

int path[l_max][l_max];

// x.{0,1} <= y.{0,1} ;
int calc_path(pair_int a, pair_int b) {
    int x = b.first - a.first;
    int y = b.second - a.second;

    return path[x][y];
}

int main(void) {
    for (int i = 0; i < l_max; i++) {
        path[0][i] = path[i][0] = 1;
    }

    for (int i = 1; i < l_max; i++) {
        for (int j = 1; j < l_max; j++) {
            path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
    }

    int m, n, k;
    cin >> n >> m >> k;
    k = k > 0 ? k - 1 : 0;

    int ans = 1;
    pair_int come_by = {k / m, k % m};
    if (k) {
        ans *= calc_path({0, 0}, come_by);
    }

    ans *= calc_path(come_by, {n - 1, m - 1});

    cout << ans << '\n';
}
