#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

typedef pair<int, int> pair_int;
typedef vector<vector<pair_int>> nearby;
typedef priority_queue<pair_int, vector<pair_int>, greater<pair_int>> pq;

vector<int> dijkstra(int n, int start, const nearby& nearby) {
	vector<int> distance(n, numeric_limits<int>::max());
	pq pq;

	distance[start] = 0;
	pq.push({0, start});

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

nearby get_nearby(int n, int e) {
	nearby nearby(n, vector<pair_int>());

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		a--;
		b--;

		nearby[a].push_back({b, c});
		nearby[b].push_back({a, c});
	}
	return nearby;
}



int main(void) {
	int n, e, v1, v2;

	cin >> n >> e;

	auto nearby = get_nearby(n, e);

	cin >> v1 >> v2;

	v1--;
	v2--;

	auto start_z = dijkstra(n, 0, nearby);
	auto start_n = dijkstra(n, n-1, nearby);
	auto start_v1 = dijkstra(n, v1, nearby);

	auto impossible = numeric_limits<int>::max();

	auto a = impossible;
	auto b = impossible;

	if (start_v1[v2] != impossible) {
		if (start_z[v1] != impossible && start_n[v2] != impossible) {
			a = start_z[v1] + start_v1[v2] + start_n[v2];
		}
		if (start_z[v2] != impossible && start_n[v1] != impossible) {
			b = start_z[v2] + start_v1[v2] + start_n[v1];
		}
	}

	if (a ==impossible && b == impossible) {
		cout << -1;
	} else {
		cout << min(a, b);
	}
}