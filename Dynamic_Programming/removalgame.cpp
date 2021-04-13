#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n, arr[5050];
ll dp[5050][5050];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) dp[i][j] = -5e14;
    for (int i = 0; i < n; ++i) dp[i][i] = arr[i];
    for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = max(arr[i], arr[i + 1]);
    for (int i = 1; i < n; ++i) dp[i][i - 1] = max(arr[i], arr[i - 1]);

    for (int j = 2; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            dp[i][i + j] = max(
                dp[i][i + j],
                min(dp[i + 2][i + j] + arr[i], dp[i + 1][i + j - 1] + arr[i]));
            dp[i][i + j] =
                max(dp[i][i + j], min(dp[i + 1][i + j - 1] + arr[i + j],
                                      dp[i][i + j - 2] + arr[i + j]));
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
