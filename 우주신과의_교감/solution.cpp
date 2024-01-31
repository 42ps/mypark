#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;

typedef pair<int, int> pair_int;
typedef pair<double, int> edge;
typedef priority_queue<edge, vector<edge>, greater<edge>> pq;

double calc_dist(pair_int x, pair_int y)
{
	unsigned long a, b;
	a = abs(x.first - y.first);
	b = abs(x.second - y.second);

	return sqrt(a * a + b * b);
}

int main(void)
{
	vector<pair_int> points;
	int n, m;
	cin >> n >> m;

	// 입력 n개 -> [point; n] -> [distance; n]
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		points.push_back({x, y});
	}

	vector<vector<double>> distance(n, vector<double>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			distance[i][j] = distance[j][i] = calc_dist(points[i], points[j]);
		}
	}

	// 입력 m개 -> in_mst[a, b] = true; already_connected.insert(a, b);
	vector<bool> in_mst(n, false);
	vector<double> least(n, numeric_limits<double>::max());
	pq pq;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		distance[x][y] = 0;
		distance[y][x] = 0;
	}

	pq.push({0, 0});

	double total = 0;
	while (!pq.empty())
	{
		auto [dist, node] = pq.top();
		pq.pop();

		if (in_mst[node])
			continue;

		in_mst[node] = true;
		total += dist;

		for (int i = 0; i < n; i++)
		{
			if (!in_mst[i] && distance[node][i] < least[i])
			{
				least[i] = distance[node][i];
				pq.push({least[i], i});
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << total;
}
