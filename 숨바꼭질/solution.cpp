#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pair_int;
typedef priority_queue<pair_int, vector<pair_int>, greater<pair_int>> pq;

void not_visited_then_push(pq& pq, vector<bool>& visited, int node, int time) {
	if (node >= 0 && !visited[node]) {
		visited[node] = true;
		pq.push({time, node});
	}
}

int main(void) {
	int n, k;

	cin >> n >> k;

	vector<bool> visited(2 * max(n, k), false);
	pq pq;
	
	pq.push({0, n});
	visited[n] = true;

	while (!pq.empty()) {
		auto [t, node] = pq.top();
		pq.pop();

		if (node == k) {
			cout << t;
			break;
		} else if (node > k) {
			not_visited_then_push(pq, visited, node - 1, t + 1);
		} else {
			not_visited_then_push(pq, visited, node * 2, t);
			not_visited_then_push(pq, visited, node + 1, t + 1);
			not_visited_then_push(pq, visited, node - 1, t + 1);
		}
	}
}