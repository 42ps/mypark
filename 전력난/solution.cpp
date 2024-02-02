#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

typedef pair<int, int> pair_int;
typedef priority_queue<pair_int, vector<pair_int>, greater<pair_int>> pq;

void solve(int m, int n)
{
	pq pq;
	vector<vector<pair_int>> nearby(m, vector<pair_int>());
	vector<bool> in_mst(m, false);
	vector<int> least(m, numeric_limits<int>::max());
	int total_cost = 0, min_cost = 0;

	// 입력->인접리스트, total_cost
	for (int i = 0; i < n; i++)
	{
		int x, y, z;

		cin >> x >> y >> z;

		nearby[x].push_back({y, z});
		nearby[y].push_back({x, z});
		total_cost += z;
	}

	pq.push({0, 0});

	while (!pq.empty())
	{
		auto [cost, node] = pq.top();
		pq.pop();

		if (in_mst[node])
			continue;

		in_mst[node] = true;
		min_cost += cost;

		for (auto [n, c] : nearby[node])
		{
			if (!in_mst[n] && c < least[n])
			{
				least[n] = c;
				pq.push({c, n});
			}
		}
	}

	cout << (total_cost - min_cost) << endl;
}

int main(void)
{
	int m, n;

	cin >> m >> n;
	while (!(n == 0 && m == 0))
	{
		solve(m, n);
		cin >> m >> n;
	}
	return 0;
}
