#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

typedef pair<double, double> point;
typedef pair<double, int> edge;
typedef priority_queue<edge, vector<edge>, greater<edge>> pq;

double calc_distance(point x, point y) {
	double a = x.first - y.first;
	double b = x.second - y.second;
	return sqrt(a * a + b * b);
}

int main(void) {
	int n;
	cin >> n;

	// 입력 -> [points; n]
	vector<point> points;
	vector<vector<double>> distance(n, vector<double>(n, 0));

	for (int i = 0; i < n; i++) {
		double a, b;
		cin >> a >> b;
		points.push_back({a, b});
	}

	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < n; j++) {
			auto dist = calc_distance(points[i], points[j]);
			distance[j][i] = distance[i][j] = dist;
		}
	}

	pq pq;
	vector<bool> visited(n, false);
	vector<double> least(n, numeric_limits<double>::max());
	double total = 0;

	pq.push({0.0, 0});

	while (!pq.empty()) {
		auto [dist, node] = pq.top();
		pq.pop();

		if (visited[node]) {
			continue;
		}

		visited[node] = true;
		total += dist;

		for (int i = 0; i < n; i++) {
			double d = distance[node][i];
			if (!visited[i] && d < least[i]){
				least[i] = d;
				pq.push({d, i});
			}
		}
	}

	cout << setprecision(3) << total;
}