#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pair_int;

int time_to_min(int time) { return (time / 100 * 60) + time % 100; }

int main(void) {
    int n;
    int m = 0;
    vector<pair_int> tmp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tmp.push_back({time_to_min(x) - 10, time_to_min(y) + 10});
    }

    sort(tmp.begin(), tmp.end());

    vector<pair_int> range;
    auto [s, e] = tmp[0];
    for (int i = 1; i < n; i++) {
        auto [x, y] = tmp[i];
        if (x <= e) {
            e = max(e, y);
            continue;
        }
        range.push_back({s, e});
        s = x;
        e = y;
    }
    range.push_back({s, e});

    s = time_to_min(1000);
    for (auto [x, y] : range) {
        e = x;
        m = max(m, e - s);
        s = y;
    }

    e = time_to_min(2200);
    m = max(m, e - s);
    cout << m << '\n';
}