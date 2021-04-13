#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int M = 1e9 + 7;
const ll M2 = (ll)M * M;
int n, m, k;

typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
vvi matmul(const vvi &v1, const vvi &v2, int mod) {
    vvi v3(v1.size(), vi(v2[0].size()));

    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v2[0].size(); ++j) {
            for (int k = 0; k < v1[0].size(); ++k) {
                v3[i][j] += v1[i][k] * v2[k][j];
                if (v3[i][j] >= M2) v3[i][j] -= M2;
            }
        }
    }

    for (int i = 0; i < v3.size(); ++i)
        for (int j = 0; j < v3[0].size(); ++j) v3[i][j] %= M;

    return v3;
}

int fast_pow(vvi base, ll power, ll mod) {
    vvi result(base.size(), vi(base[0].size()));
    for (int i = 0; i < result.size(); ++i) result[i][i] = 1;
    while (power) {
        if (power & 1 == 1) result = matmul(result, base, mod);
        base = matmul(base, base, mod);
        power >>= 1;
    }
    return result[0][n - 1];
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    vvi adj(n, vi(n));
    for (int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b);
        --a, --b;
        adj[a][b] += 1;
    }

    cout << fast_pow(adj, k, M);
    return 0;
}
