#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<int> coin(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    reverse(coin.begin(), coin.end());

    int count = 0;

    for (auto c : coin)
    {
        count += k / c;
        k %= c;
    }

    cout << count << '\n';
}