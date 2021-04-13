#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

ll solve(ll n) {
    if (n == 0) return 1;
    if (n == -1) return 0;

    ll total = 0, cc = 9;
    string s = to_string(n);

    for (ll i = 1; i < s.length(); ++i) total += cc, cc *= 9;

    int digs[22];
    for (int i = 0; i < s.length(); ++i) digs[i] = s[i] - '0';

    ll dp[10][s.length()];
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < s.length(); ++j) dp[i][j] = 0;

    for (int i = 1; i <= digs[0]; ++i) dp[i][0] = 1;

    bool sat = true;
    for (int j = 1; j < s.length(); ++j) {
        if (j >= 2 && digs[j - 1] == digs[j - 2]) sat = false;
        for (int k = 0; k < 10; ++k) {
            for (int i = 0; i < 10; ++i) {
                if (k == i) continue;
                dp[i][j] += dp[k][j - 1];
            }
        }
        for (int i = digs[j] + 1; i < 10; ++i)
            if (i != digs[j - 1] && sat) dp[i][j]--;
    }
    for (int i = 0; i < 10; ++i) total += dp[i][s.length() - 1];

    return total + 1;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;

    return 0;
}
