#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void not_visited_then_push(queue<pair<int, int>> &q, vector<bool> &visited, int pos, int step)
{
    if (pos >= 0 && pos < visited.size() && !visited[pos])
    {
        visited[pos] = true;
        q.push({pos, step + 1});
    }
}

int main(void)
{
    int src = 0, dst = 0;

    cin >> src >> dst;

    vector<bool> visited(2 * max(src, dst), false);
    queue<pair<int, int>> q;

    visited[src] = true;
    q.push({src, 0});

    while (!q.empty())
    {
        auto [pos, step] = q.front();
        q.pop();

        if (pos == dst)
        {
            cout << step << '\n';
            break;
        }
        else if (pos > dst)
        {
            not_visited_then_push(q, visited, pos - 1, step);
        }
        else
        {
            not_visited_then_push(q, visited, pos - 1, step);
            not_visited_then_push(q, visited, pos + 1, step);
            not_visited_then_push(q, visited, pos * 2, step);
        }
    }
}