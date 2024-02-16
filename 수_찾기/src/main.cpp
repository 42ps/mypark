#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int n, m, j;

    cin >> n;
    vector<int> a(n, 0);
    for (int i=0; i<n; i++){
        cin >> j;
        a[i] = j;
    }

    sort(a.begin(), a.end());

    cin >> m;
    vector<int> b(m, 0);
    for (int i=0; i<m; i++){
        cin >> j;
	    b[i] = j;
    }

    string result;
    for (auto bb: b) {
        if (binary_search(a.begin(), a.end(), bb)) {
	        result.append("1\n");
        } else {
            result.append("0\n");
        }
    }

    cout << result;
}