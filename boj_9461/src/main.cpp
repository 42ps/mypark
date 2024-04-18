#include <iostream>

using namespace std;

size_t p[101] = {
    1,
    1,
    1,
    2,
    2,
};

int main(void)
{
    cin.tie(NULL);

    for (int i = 5; i <= 100; i++)
    {
        p[i] = p[i - 1] + p[i - 5];
    }

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << p[n - 1] << '\n';
    }
}