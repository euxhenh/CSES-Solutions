#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int M = 1e9 + 7;

int main() {
    int n;
    char grid[1010][1010];
    int dp[1010][1010];
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> grid[i][j];

    int trap1 = 1, trap2 = 1;
    for (int i = 0; i < n; ++i) {
        if (grid[i][0] == '*') trap1 = 0;
        if (grid[0][i] == '*') trap2 = 0;
        dp[i][0] = trap1;
        dp[0][i] = trap2;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == '*')
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
        }
    }
    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
