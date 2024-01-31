#include <iostream>
#include <queue>

using namespace std;

int solve(void) {
	int v, e;

	cin >> v >> e;

	queue<int> q;
	vector<vector<int>> nearby(v, vector<int>());
	vector<bool> visited(v, false);

	for (int i = 0; i < e; ++i) {
		int a, b;
		cin >> a >> b;
		nearby[a - 1].push_back(b - 1);
		nearby[b - 1].push_back(a - 1);
	}

	int plane_count = -1;
	q.push(0);
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (visited[node])
			continue;
				
		visited[node] = true;
		plane_count++;
		
		for (auto to: nearby[node]) {
			if (!visited[to]) {
				q.push(to);
			}
		}
	}

	return plane_count;
}

int main(void) {

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cout << solve() << endl;
	}

	return 0;
}