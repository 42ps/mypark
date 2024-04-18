#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    size_t n;
    cin >> n;

    vector<size_t> v(n + 1, 0);

    v[1] = 1;
    v[2] = 2;

    for (size_t i = 3; i <= n; i++)
    {
        v[i] = v[i - 2] + v[i - 1];
        v[i] %= 10007;
    }

    cout << v[n] << '\n';
}