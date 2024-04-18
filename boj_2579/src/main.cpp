#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> stairs(n, 0);
    vector<int> np(n, 0);
    vector<int> pv(n, 0);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> stairs[i];
        sum += stairs[i];
    }

    if (n <= 2)
    {
        cout << sum << '\n';
        return 0;
    }

    np[1] = stairs[1];
    pv[0] = stairs[0];
    pv[1] = pv[0] + stairs[1];

    for (int i = 2; i < n; i++)
    {
        pv[i] = stairs[i] + np[i - 1];
        np[i] = stairs[i] + max(np[i - 2], pv[i - 2]);
    }

    cout << max(np[n - 1], pv[n - 1]) << '\n';
    return 0;
}