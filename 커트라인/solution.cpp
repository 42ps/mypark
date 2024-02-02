#include <iostream>
#include <vector>

using namespace std;

void q_sort(vector<int> &arr, int low, int high)
{
	if (low >= high)
		return;

	int pivot = arr[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (arr[j] > pivot)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}

	swap(arr[i], arr[high]);
	q_sort(arr, low, i - 1);
	q_sort(arr, i + 1, high);
}

int main(void)
{
	int n, k;
	vector<int> scores;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		scores.push_back(x);
	}

	q_sort(scores, 0, n - 1);
	cout << scores[k - 1];
}