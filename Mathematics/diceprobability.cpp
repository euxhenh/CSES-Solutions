#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

double dp[660][110]{};
int n, a, b;

void fsolve() {
    for (int i = 1; i <= 6; ++i) dp[i][1] = 1.0 / 6.0;
    for (int i = 7; i < 660; ++i) dp[i][1] = 0;
    for (int i = 1; i < 110; ++i) dp[0][i] = 0;

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= 600; ++j) {
            dp[j][i] += dp[max(j - 6, 0)][i - 1];
            dp[j][i] += dp[max(j - 5, 0)][i - 1];
            dp[j][i] += dp[max(j - 4, 0)][i - 1];
            dp[j][i] += dp[max(j - 3, 0)][i - 1];
            dp[j][i] += dp[max(j - 2, 0)][i - 1];
            dp[j][i] += dp[j - 1][i - 1];
            dp[j][i] *= 1.0 / 6.0;
        }
    }
}

int main() {
    cin >> n >> a >> b;

    double prob = 0;
    fsolve();
    for (int i = a; i <= b; ++i) prob += dp[i][n];
    printf("%.6f", prob);
    return 0;
}
