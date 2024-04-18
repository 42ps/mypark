#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int recursive_dp(vector<int>& dp, int n) {
    if (dp[n] != INT32_MAX) {
        return dp[n];
    }

    for (int i = (int)sqrt((float)n); i >= 1; i--) {
        dp[n] = min(dp[n], recursive_dp(dp, n - i * i) + 1);
    }

    return dp[n];
}

int main(void) {
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT32_MAX);

    dp[0] = 0;
    dp[1] = 1;

    cout << recursive_dp(dp, n) << '\n';
}