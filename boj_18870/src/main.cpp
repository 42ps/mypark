#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pair_int;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    size_t n;
    cin >> n;

    vector<pair_int> numbers;
    numbers.reserve(n);

    for (size_t i = 0; i < n; i++) {
        ssize_t x;
        cin >> x;
        numbers.push_back({x, i});
    }

    sort(numbers.begin(), numbers.end());

    vector<int> compressed(n, 0);
    int prev = numbers[0].first;
    int order = 0;

    for (auto [num, index] : numbers) {
        if (prev != num) order++;
        compressed[index] = order;
        prev = num;
    }

    for (int i = 0; i < n - 1; i++) {
        cout << compressed[i] << ' ';
    }
    cout << compressed[n - 1] << '\n';
}
