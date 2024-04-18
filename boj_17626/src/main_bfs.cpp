#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

// int b_search(int *sqaure, int x)
// {
//     int lo = -1;
//     int hi = 301;

//     while (lo + 1 < hi)
//     {
//         int m = (lo + hi) / 2;
//         if (sqaure[m] <= x)
//             lo = m;
//         else
//             hi = m;
//     }
//     return lo;
// }

int main(void)
{
    int n;
    cin >> n;

    int square[301] = {0};

    for (int i = 0; i < 301; i++)
    {
        square[i] = i * i;
    }

    queue<pair<int, int>> q;

    q.push({n, 0});

    while (!q.empty())
    {
        auto [c, depth] = q.front();
        q.pop();

        if (c == 0)
        {
            cout << depth << '\n';
            break;
        }
        else
        {
            int b = (int)sqrt((float)c);
            int hc = c / 4;

            for (; b >= 0 && square[b] >= hc; b--)
            {
                q.push({c - square[b], depth + 1});
            }
        }
    }
}