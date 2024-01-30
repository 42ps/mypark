#include <vector>
#include <iostream>

using namespace std;

int visit_connected_nodes(const vector<vector<int>> &connected, vector<int> &visited, int start_node)
{
	int x = start_node;
	int n = visited.size();
	int sum = 1;

	visited[x] = 1;

	for (int i = 0; i < n; ++i)
	{
		if (connected[x][i] && visited[i] == 0)
		{
			sum += visit_connected_nodes(connected, visited, i);
		}
	}
	return sum;
}

int find_not_visited(vector<int> visited)
{
	for (auto i = 0; i < visited.size(); ++i)
	{
		if (visited[i] == 0)
		{
			return i;
		}
	}

	cout << "invaild case" << endl;
	exit(1);
}

int solution(int n, vector<vector<int>> wires)
{
	vector<int> visited;
	vector<vector<int>> connected;
	int result = 100;
	int n_1, n_2;

	for (int i = 0; i < n; i++)
	{
		connected.push_back(vector<int>());
		connected[i].assign(n, 0);
	}

	for (auto w : wires)
	{
		connected[w[0] - 1][w[1] - 1] = 1;
		connected[w[1] - 1][w[0] - 1] = 1;
	}

	for (auto w : wires)
	{
		visited.assign(n, 0);

		int x = w[0] - 1;
		int y = w[1] - 1;

		connected[x][y] = 0;
		connected[y][x] = 0;

		n_1 = visit_connected_nodes(connected, visited, 0);

		int not_visited = find_not_visited(visited);

		n_2 = visit_connected_nodes(connected, visited, not_visited);

		connected[x][y] = 1;
		connected[y][x] = 1;

		result = min(result, abs(n_1 - n_2));
	}

	return result;
}

#include <cassert>
int main(void)
{
	{
		vector<vector<int>> wires;
		vector<int> w1;

		w1.push_back(1);
		w1.push_back(2);

		wires.push_back(w1);

		assert(solution(2, wires) == 0);
	}
	{
		vector<vector<int>> wires;
		vector<int> w1;
		vector<int> w2;

		w1.push_back(1);
		w1.push_back(2);
		w2.push_back(2);
		w2.push_back(3);

		wires.push_back(w1);
		wires.push_back(w2);

		assert(solution(3, wires) == 1);
	}
}
