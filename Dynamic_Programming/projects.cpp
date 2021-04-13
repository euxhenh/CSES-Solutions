#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int lb(const vector<ar<ll, 4>> &arr, int l, int r, ll x) {
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m][0] < x)
            l = m + 1;
        else
            r = m;
    }
    if (arr[r][0] >= x) return r;
    return r + 1;
}

int main() {
    ll n, a, b, p, dp[200200];
    vector<ar<ll, 4>> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> p;
        v.push_back({b, a, 0, p});
    }
    v.push_back({0, 0, 0, 0});
    fill(dp, dp + 200200, 0);
    sort(v.begin(), v.end());
    ++n;
    for (int i = 0; i < n; ++i) v[i][2] = i;

    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        ll val = lb(v, 0, n - 1, v[i][1]);
        --val;
        dp[v[i][2]] = max(dp[v[i - 1][2]], dp[val] + v[i][3]);
    }
    cout << dp[n - 1] << endl;
    return 0;
}
