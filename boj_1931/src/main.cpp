#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pair_int;

int main(void)
{
    priority_queue<pair_int, vector<pair_int>, greater<pair_int>> pq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;

        pq.push({e, s});
    }

    int time = 0;
    int count = 0;
    while (!pq.empty())
    {
        auto [end, start] = pq.top();
        pq.pop();

        if (start < time)
            continue;

        time = end;
        count++;
    }

    cout << count << '\n';
}