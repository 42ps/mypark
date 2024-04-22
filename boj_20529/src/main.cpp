#include <iostream>
#include <map>
#include <vector>

using namespace std;

int calc_dist(const string& a, const string& b) {
    int dist = 0;
    for (int i = 0; i < 4; i++) {
        dist += (a[i] != b[i]);
    }
    return dist;
}

int solve(void) {
    int n;
    cin >> n;

    vector<string> mbti;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        mbti.push_back(x);
    }

    if (n > 32) {
        return 0;
    }

    int ans = INT32_MAX;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                if (x == y || y == z || z == x) continue;

                int dist = 0;
                dist += calc_dist(mbti[x], mbti[y]);
                dist += calc_dist(mbti[y], mbti[z]);
                dist += calc_dist(mbti[z], mbti[x]);

                ans = min(ans, dist);
            }
        }
    }

    return ans;
}

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << solve() << '\n';
    }
}