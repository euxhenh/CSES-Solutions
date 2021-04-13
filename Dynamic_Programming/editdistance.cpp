#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int dp[5050][5050];
string s, t;

int solve(int n, int m) {
    if (dp[n][m] != -1) return dp[n][m];

    if (s[n - 1] == t[m - 1])
        dp[n][m] = solve(n - 1, m - 1);
    else
        dp[n][m] =
            1 + min(solve(n - 1, m), min(solve(n - 1, m - 1), solve(n, m - 1)));
    return dp[n][m];
}

int main() {
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) dp[i][j] = -1;

    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int i = 0; i <= m; ++i) dp[0][i] = i;

    cout << solve(n, m) << endl;

    return 0;
}
