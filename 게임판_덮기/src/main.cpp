#include <vector>
#include <iostream>

typedef long int i64;

using namespace std;

vector<vector<bool>> read_map(i64 h, i64 w, i64 &empty_count) {
	vector<vector<bool>> result;

	char x;
	for (int i = 0; i < h; i++) {
		vector<bool> v;
		result.push_back(v);
		for (int j = 0; j < w; j++) {
			result[i].push_back(false);
			cin >> x;

			if (x == '#') {
				result[i][j] = true;
			} else {
				empty_count++;
				result[i][j] = false;
			}
		}
	}

	return result;
}

const i64 BLOCKS[4][3][2] = {
	{{0, 1}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}}, // ㄴ
	{{0, 0}, {0, 1}, {1, 0}},
	{{0, 0}, {0, 1}, {1, 1}}, // ㄱ
};


vector<i64> get_putables(const vector<vector<bool>>& map, i64 x, i64 y) {
	vector<i64> result;
	int s = 1;

	if (map[x][y])
		s--;

	for (int bi = s; bi < 4; bi ++) {
		bool possible = true;
		for (int pi = 0; pi < 3; pi++) {
			i64 i = x + BLOCKS[bi][pi][0];
			i64 j = y + BLOCKS[bi][pi][1];
			if (map[i][j]) {
				possible = false;
			}
		}

		if (possible) {
			result.push_back(bi);
		}
	}

	return result;
}

void put_block(vector<vector<bool>>& map, i64 x, i64 y, i64 b) {
	for (int pi = 0; pi < 3; pi++) {
		i64 i = x + BLOCKS[b][pi][0];
		i64 j = y + BLOCKS[b][pi][1];
		map[i][j] = true;
	}
}

void remove_block(vector<vector<bool>>& map, i64 x, i64 y, i64 b) {
	for (int pi = 0; pi < 3; pi++) {
		i64 i = x + BLOCKS[b][pi][0];
		i64 j = y + BLOCKS[b][pi][1];
		map[i][j] = false;
	}
}

// empty_count % 3 == 0
i64 find_case(vector<vector<bool>>& map, i64 index, i64 blk_cnt, i64 empty_count) {
	if (blk_cnt == empty_count / 3) {
		return 1;
	}

	i64 h = map.size();
	i64 w = map[0].size();
	i64 end = (w - 1) * (h - 1);
	i64 sum = 0;

	for (int i = index; i < end; i++) {
		i64 x = i / (w - 1);
		i64 y = i % (w - 1);
		vector<i64> blocks = get_putables(map, x, y);

		for (auto b: blocks) {
			put_block(map, x, y, b);

			sum += find_case(map, i + 1, blk_cnt + 1, empty_count);

			remove_block(map, x, y, b);
		}

		if (!map[x][y])
			break;
	}

	return sum;
}

int main(void) {
	i64 c;
	cin >> c;

	for (int i = 0; i < c; i++) {
		i64 h, w;
		i64 empty_count = 0, case_cnt = 0;
		cin >> h >> w;

		vector<vector<bool>> map = read_map(h, w, empty_count);

		if (empty_count % 3 == 0) {
			case_cnt = find_case(map, 0, 0, empty_count);
		}

		cout << case_cnt << '\n';
	}
}

