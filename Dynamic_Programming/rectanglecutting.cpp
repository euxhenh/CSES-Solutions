#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int dp[505][505];

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i <= a; ++i)
        for (int j = 0; j <= b; ++j) dp[i][j] = INT_MAX;
    for (int i = 1; i <= a; ++i) dp[1][i] = dp[i][1] = i - 1;
    for (int i = 1; i <= min(a, b); ++i) dp[i][i] = 0;

    for (int x = 1; x <= a; ++x) {
        for (int y = 1; y <= b; ++y) {
            for (int i = 1; i < x; ++i)
                dp[x][y] = dp[y][x] = min(dp[x][y], 1 + dp[x - i][y] + dp[i][y]);
            for (int j = 1; j < y; ++j)
                dp[x][y] = dp[y][x] = min(dp[x][y], 1 + dp[x][y - j] + dp[x][j]);
        }
    }

    cout << dp[a][b] << endl;
    return 0;
}
