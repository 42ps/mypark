#include <queue>
#include <vector>
#include <iostream>
#include <limits>
#include <map>

using namespace std;

typedef pair<int, int> pair_int;
typedef priority_queue<pair_int, vector<pair_int>, greater<pair_int>> pq;

vector<map<int, int>> get_nearby(const int v, const int e) {
	vector<map<int, int>> nearby(v, map<int, int>());

	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		auto [iter, success] = nearby[a].insert({b, w});
		if (!success)
			nearby[a][b] = nearby[a][b] < w ? nearby[a][b] : w;
	}
	return nearby;
}

vector<int> dijkstra(const int v, const int k, const vector<map<int, int>>& nearby) {
	vector<int> distance(v, numeric_limits<int>::max());
	distance[k] = 0;

	pq pq;
	pq.push({0, k}); // distance, node number

	while (!pq.empty()) {
		auto [dist_u, u] = pq.top();
		pq.pop();

		for (auto [v, w]: nearby[u]) {
			auto dist_v = dist_u + w;
			if (dist_v < distance[v]) {
				distance[v] = dist_v;
				pq.push({dist_v, v});
			}
		}
	}
	return distance;
}

int main(void) {
	int v, e, k;

	cin >> v >> e >> k;
	k--;

	auto nearby = get_nearby(v, e);
	auto distance = dijkstra(v, k, nearby);
		
	for(auto d: distance) {
		if (d == numeric_limits<int>::max()) {
			cout << "INF" << '\n';
		} else {
			cout << d << '\n';
		}
	}
}

