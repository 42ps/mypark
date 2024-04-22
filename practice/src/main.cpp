#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> a(2, 0), b(2, 1);
    auto x = [](const vector<int>& a, const vector<int>& b) -> bool {
        return a[1] < b[1];
    };

    cout << x(a, b) << '\n';
}