// string

// input: 1 <= n, m <= 1,000,000, S: string
// output: nr needle

#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    string needle, heystack;

    cin >> n >> m;
    cin >> heystack;

    for (int i = 0; i < n; i++) {
        needle += "IO";
    }
    needle += "I";

    int s = heystack.find('I', 0);
    int cnt = 0;
    int i = 0;
    while (s < m) {
        for (; i < needle.size(); i++) {
            if (heystack[s + i] != needle[i]) break;
        }
        if (i == needle.size()) {
            cnt++;
            s += 2;
            i = needle.size() - 2;
        } else {
            s += i + !(i % 2);
            i = 0;
        }
    }

    cout << cnt << '\n';

    return 0;
}