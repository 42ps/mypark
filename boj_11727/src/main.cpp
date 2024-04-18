#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    size_t arr[1001] = {0};

    arr[1] = 1;
    arr[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] * 2;
        arr[i] %= 10007;
    }

    cout << arr[n] << '\n';
}