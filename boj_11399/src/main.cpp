#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    size_t n;
    cin >> n;

    vector<size_t> times(0, n);

    for (auto i = 0; i < n; i++)
    {
        auto x = 0;
        cin >> x;
        times.push_back(x);
    }

    sort(times.begin(), times.end());

    for (auto i = 1; i < n; i++)
    {
        times[i] += times[i - 1];
    }

    cout << accumulate(times.begin(), times.end(), 0) << '\n';
}