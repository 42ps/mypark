#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> number(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }

    vector<int> acc(n, 0);
    acc[0] = number[0];
    for (int i = 1; i < n; i++) {
        acc[i] = acc[i - 1] + number[i];
    }

    int m = acc[k - 1];
    for (int i = k; i < n; i++) {
        m = max(m, acc[i] - acc[i - k]);
    }

    cout << m << '\n';
}