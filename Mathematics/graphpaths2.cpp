#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n, m, k;

typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
vvi matmul(const vvi &v1, const vvi &v2) {
    vvi v3(v1.size(), vi(v2[0].size()));

    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v2[0].size(); ++j) {
            v3[i][j] = 2e18;
            for (int k = 0; k < v1[0].size(); ++k) {
                v3[i][j] = min(v3[i][j], v1[i][k] + v2[k][j]);
            }
        }
    }

    return v3;
}

ll fast_pow(vvi base, ll power) {
    vvi result(base.size(), vi(base[0].size()));
    for (int i = 0; i < result.size(); ++i)
        for (int j = 0; j < result[0].size(); ++j) result[i][j] = 2e18;
    for (int i = 0; i < result.size(); ++i) result[i][i] = 0;
    while (power) {
        if (power & 1 == 1) result = matmul(result, base);
        base = matmul(base, base);
        power >>= 1;
    }
    return result[0][n - 1];
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    vvi adj(n, vi(n));
    for (int i = 0; i < adj.size(); ++i)
        for (int j = 0; j < adj[0].size(); ++j) adj[i][j] = 2e18;
    for (int i = 0, a, b, c; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        adj[a][b] = min(adj[a][b], (ll)c);
    }

    ll res = fast_pow(adj, k);
    if (res >= 2e18)
        cout << -1;
    else
        cout << res;
    return 0;
}
