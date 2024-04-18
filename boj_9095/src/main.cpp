#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);

    size_t T, n;

    size_t arr[12] = {0};

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 1 + arr[2] + arr[1];

    for (size_t i = 4; i <= 11; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }

    cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        cin >> n;
        cout << arr[n] << '\n';
    }
}