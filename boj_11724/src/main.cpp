#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void tour_graph(const vector<vector<size_t>> &adj_list, size_t no, vector<bool> &visit)
{
    queue<size_t> q;

    q.push(no);

    visit[no] = true;

    while (!q.empty())
    {
        size_t c = q.front();
        q.pop();

        for (auto n : adj_list[c])
        {
            if (!visit[n])
            {
                visit[n] = true;
                q.push(n);
            }
        }
    }
}

int main(void)
{
    size_t n, m;

    cin >> n >> m;

    vector<vector<size_t>> adj_list(n, vector<size_t>());

    for (size_t i = 0; i < m; i++)
    {
        size_t x, y;
        cin >> x >> y;

        x -= 1;
        y -= 1;

        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    vector<bool> visit(n, false);
    size_t count = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            tour_graph(adj_list, i, visit);
            count++;
        }
    }

    cout << count << '\n';
}