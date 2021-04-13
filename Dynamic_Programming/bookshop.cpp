#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int n, x, h[1010], s[1010], dp[100100];
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < n; ++i) cin >> s[i];
    fill(dp, dp + x + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = x; j; --j) {
            if (j >= h[i]) dp[j] = max(dp[j], s[i] + dp[j - h[i]]);
        }
    }
    cout << dp[x] << endl;
    return 0;
}
