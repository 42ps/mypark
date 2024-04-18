#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

size_t sum_the_rest_after_cutting(const vector<int>& tree, int height) {
    size_t sum = 0;
    for (auto e : tree) {
        sum += max(e - height, 0);
    }
    return sum;
}

int b_search(const vector<int>& tree, size_t need, int max_height) {
    int lo = -1;
    int hi = max_height;

    while (lo + 1 < hi) {
        int m = (lo + hi) / 2;
        size_t total = sum_the_rest_after_cutting(tree, m);
        if (total >= need)
            lo = m;
        else
            hi = m;
    }
    return lo;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(0);

    int n = 0, mx = 0;
    size_t need = 0;
    cin >> n;
    cin >> need;

    vector<int> tree(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        mx = max(mx, tree[i]);
    }

    cout << b_search(tree, need, mx) << '\n';
}