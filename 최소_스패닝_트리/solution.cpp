#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> pair_int;
typedef priority_queue<pair_int, vector<pair_int>, greater<pair_int>> pq;

int main(void) {
	int v, e;
	int total = 0;
	pq pq;

	cin >> v >> e;

	vector<vector<pair_int>> nearby(v, vector<pair_int>());
	vector<bool> in_mst(v, false);
	vector<int> least(v, INT_MAX);

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		nearby[a - 1].push_back({b - 1, c});
		nearby[b - 1].push_back({a - 1, c});
	}

	pq.push({0, 0});

	while (!pq.empty()) {
		auto [cost, node] = pq.top();
		pq.pop();

		if (in_mst[node])
			continue;

		in_mst[node] = true;
		total += cost;
		
		for (auto [to, c]: nearby[node]) {
			if(!in_mst[to] && c < least[to]) {
				least[to] = c;
				pq.push({c, to});
			}
		}
	}

	cout << total;
}