#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pair_int;

int main(void) {
    int n;
    cin >> n;

    vector<pair_int> sticks(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        sticks.push_back({x, y});
    }

    sort(sticks.begin(), sticks.end());
    auto max_e = max_element(sticks.begin(), sticks.end(), [](auto x, auto y) {
        return x.second < y.second;
    });

    int l = 0;
    int h = 0;
    int ans = max_e->second;

    for (auto s = sticks.begin(); s != max_e; s++) {
        auto [cl, ch] = *s;
        if (ch >= h) {
            ans += (cl - l) * h;
            l = cl;
            h = ch;
        }
    }

    ans += (max_e->first - l) * h;

    l = sticks.end()->first;
    h = 0;
    for (auto s = sticks.end() - 1; s != max_e; s--) {
        auto [cl, ch] = *s;
        if (ch >= h) {
            ans += (l - cl) * h;
            l = cl;
            h = ch;
        }
    }

    ans += (l - max_e->first) * h;

    cout << ans << '\n';
}