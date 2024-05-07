#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    string tmp;
    tmp.reserve(100000);

    cin >> tmp;

    string sticks;
    sticks.reserve(100000);

    int i = 0;
    for (; i < tmp.size() - 1; i++) {
        if (tmp[i] == '(' && tmp[i + 1] == ')') {
            sticks.push_back('x');
            i++;
        } else {
            sticks.push_back(tmp[i]);
        }
    }

    if (i != tmp.size()) {
        sticks.push_back(tmp.back());
    }

    int ans = 0;
    int height = 0;
    for (auto c : sticks) {
        switch (c) {
            case 'x':
                ans += height;
                break;
            case '(':
                height++;
                break;
            case ')':
                height--;
                ans += 1;
                break;
        }
    }

    cout << ans << '\n';
}