#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int lcd(int a, int b) {
    int g = gcd(a, b);

    return a / g * b;
}

void solve(void) {
    int m, n, x, y;
    cin >> m >> n >> x >> y;

    int l = lcd(m, n);

    x -= 1;
    y -= 1;

    int ans = -1;
    for (int k = x; k < l; k += m) {
        if (k % n == y) {
            ans = k + 1;
            break;
        }
    }

    cout << ans << '\n';
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }

    return 0;
}
