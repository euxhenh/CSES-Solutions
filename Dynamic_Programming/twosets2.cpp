#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int n, M = 1e9 + 7;
    cin >> n;
    int ts = n * (n + 1) / 2;
    if (ts % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    ts /= 2;
    int dp[500 * 501 / 4 + 510];
    fill(dp, dp + 500 * 501 / 4 + 510, 0);
    dp[0] = 1;
    for (int j = 1; j <= n; ++j) {
        for (int i = ts; i; --i) {
            if (i >= j) dp[i] = (dp[i] + dp[i - j]) % M;
        }
    }
    cout << ((ll)500000004 * dp[ts]) % M << endl;
    return 0;
}
