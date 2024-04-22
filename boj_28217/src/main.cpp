#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> paper;

paper input_triangle(int n) {
    paper tri(n, vector<int>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int x;
            cin >> x;
            tri[i].push_back(x);
        }
    }

    return tri;
}

paper rotate(paper op) {
    int n = op.size();
    int m = n - 1;

    paper np = vector(n, vector<int>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            np[i].push_back(0);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            np[j + m - i][m - i] = op[i][j];
        }
    }
    return np;
}

void flip(paper& tri) {
    int n = tri.size();

    for (int i = 0; i < n; i++) {
        reverse(tri[i].begin(), tri[i].end());
    }
}

int diff(const paper& a, const paper& b) {
    int n = a.size();
    int c = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (a[i][j] != b[i][j]) c++;
        }
    }
    return c;
}

int main(void) {
    int n;  // [1, 10]
    cin >> n;

    auto a = input_triangle(n);
    auto b = input_triangle(n);

    int m = INT32_MAX;

    for (int i = 0; i < 3; i++) {
        a = rotate(a);
        m = min(m, diff(a, b));
    }

    flip(a);

    for (int i = 0; i < 3; i++) {
        a = rotate(a);
        m = min(m, diff(a, b));
    }

    cout << m << '\n';
}

// for (int i = 0; i < n; i++) {
//     for (int j = 0; j <= i; j++) {
//         cout << a[i][j] << ' ';
//     }
//     cout << '\n';
// }