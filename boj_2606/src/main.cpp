#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int main(void)
{
    size_t n, e;

    cin >> n;

    vector<vector<size_t>> adj_list(n);

    cin >> e;

    for (size_t i = 0; i < e; i++)
    {
        size_t s, d;

        cin >> s >> d;

        s -= 1;
        d -= 1;

        adj_list[s].push_back(d);
        adj_list[d].push_back(s);
    }

    vector<size_t> infection(n, 0);
    queue<size_t> q;
    size_t cnt = 0;

    q.push(0);
    infection[0] = 1;

    while (!q.empty())
    {
        size_t c = q.front();
        q.pop();

        for (auto n : adj_list[c])
        {
            if (!infection[n])
            {
                infection[n] = 1;
                q.push(n);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
}