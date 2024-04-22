#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef pair<char, int> command;

void solve(void) {
    int K;  // [0, 1,000,000]
    cin >> K;

    map<int, int> q;
    while (K--) {
        int x;
        char c;
        cin >> c >> x;

        switch (c) {
            case 'I':
                q[x]++;
                break;
            case 'D':
                if (q.empty()) continue;
                auto i = x > 0 ? (--q.end()) : q.begin();
                if (i->second <= 1)
                    q.erase(i);
                else
                    i->second = i->second - 1;
        }
    }

    if (!q.empty())
        cout << (--q.end())->first << ' ' << q.begin()->first << '\n';
    else
        cout << "EMPTY" << '\n';
}

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T;  // ?
    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }
}