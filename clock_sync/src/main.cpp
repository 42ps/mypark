#include <iostream>
#include <vector>

using namespace std;


vector<vector<int> > button({
    vector<int>( { 0, 1, 2 }),
    vector<int>( { 3, 7, 9, 11 }),
    vector<int>( { 4, 10, 14, 15 }),
    vector<int>( { 0, 4, 5, 6, 7 }),
    vector<int>( { 6, 7, 8, 10, 12 }),
    vector<int>( { 0, 2, 14, 15 }),
    vector<int>( { 3, 14, 15 }),
    vector<int>( { 4, 5, 7, 14, 15 }),
    vector<int>( { 1, 2, 3, 4, 5 }),
    vector<int>( { 3, 4, 5, 9, 13 })
});

void change_clocks(int num, vector<int>& clocks, int add) {

	for (int i = 0; i < button[num].size(); i++) {
		auto clk = button[num][i];
		clocks[clk] += add;
	}
}

bool is_all_12(const vector<int>& clocks) {
	for (auto c: clocks) {
		if (c % 4 != 0) {
			return false;
		}
	}

	return true;
}


void find_case(vector<int>& clocks, int press_count, int& min_count, int start) {
	if (is_all_12(clocks)) {
		min_count = press_count;
		return;
	}

	for (int i = start; i < 10; i++ ) {
		for (int a = 1; a <= 3; a++) {
			change_clocks(i, clocks, a);

			find_case(clocks, press_count + a, min_count, i + 1);

			change_clocks(i, clocks, a * -1);
		}
	}
}

void solve(vector<int> clocks) {
	int output = 31;

	find_case(clocks, 0, output, 0);

	if (output == 31) {
		cout << -1;
	} else {
		cout << output;
	}
	cout << '\n';
}

int main(void) {
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		vector<int> v;
		int clk;
		for (int j = 0; j < 16 ; j++) {
			cin >> clk;
			v.push_back(clk / 3);
		}
		solve(v);
	}
}