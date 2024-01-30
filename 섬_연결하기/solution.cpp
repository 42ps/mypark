#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pq_element;
typedef priority_queue<pq_element, vector<pq_element>, greater<pq_element>> pq;

int solution(int n, vector<vector<int>> costs)
{
	vector<vector<pair<int, int>>> nearby(n, vector<pair<int, int>>());
	vector<bool> in_mst(n, false);
	vector<int> least(n, INT_MAX);
	pq pq;
	int total_cost = 0;

	for (auto c : costs)
	{
		nearby[c[0]].push_back({c[1], c[2]});
		nearby[c[1]].push_back({c[0], c[2]});
	}

	pq.push({0, 0});

	while (!pq.empty())
	{
		auto [cost, node] = pq.top();
		pq.pop();

		if (in_mst[node])
		{
			continue;
		}

		in_mst[node] = true;
		total_cost += cost;

		for (auto [n, c] : nearby[node])
		{
			if (!in_mst[n] && c < least[n])
			{
				least[n] = c;
				pq.push({c, n});
			}
		}
	}
	return total_cost;
}