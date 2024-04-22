#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>

using namespace std;

deque<int> input_array() {
    int n;
    cin >> n;

    deque<int> arr(n, 0);
    string arr_input;
    cin >> arr_input;

    stringstream ss;
    ss << arr_input;

    char c;
    ss >> c;
    for (int i = 0; i < n; i++) {
        ss >> arr[i];
        ss >> c;
    }
    return arr;
}

void output_array(const deque<int>& arr) {
    cout << '[';
    if (!arr.empty()) cout << arr[0];
    for (int i = 1; i < arr.size(); i++) {
        cout << ',' << arr[i];
    }
    cout << "]\n";
}

void solve(void) {
    string cmd;
    cin >> cmd;

    auto arr = input_array();
    bool reversed = false;
    for (auto c : cmd) {
        switch (c) {
            case 'R':
                reversed = !reversed;
                break;
            case 'D':
                if (arr.empty()) {
                    cout << "error" << '\n';
                    return;
                } else {
                    if (reversed)
                        arr.pop_back();
                    else
                        arr.pop_front();
                }
        }
    }

    if (reversed) reverse(arr.begin(), arr.end());
    output_array(arr);
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }
}