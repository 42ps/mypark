#include <iostream>
#include <queue>
#include <stack>

using namespace std;

string give_snack(queue<int> q) {
    stack<int> st;
    int next = 1;

    while (!q.empty()) {
        int f = q.front();

        if (f == next) {
            q.pop();
            next++;
        } else if (!st.empty() && st.top() == next) {
            st.pop();
            next++;
        } else {
            if (st.empty() || f < st.top()) {
                q.pop();
                st.push(f);
            } else {
                return "Sad";
            }
        }
    }

    return "Nice";
}

int main(void) {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << give_snack(q) << '\n';
}