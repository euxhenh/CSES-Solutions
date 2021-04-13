#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

ll n, m, q, a, b, c;
ll cost[510][510];
vector<vector<ll>> adj(510);

int main() {
    for (int i = 0; i < 510; ++i)
        for (int j = i; j < 510; ++j) cost[i][j] = cost[j][i] = 1e12;

    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cost[a][b] = cost[b][a] = min(cost[a][b], c);
    }
    for (int i = 0; i < n; ++i) cost[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cost[i][j] = cost[j][i] =
                    min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    while (q--) {
        cin >> a >> b, --a, --b;
        if (cost[a][b] >= 1e12)
            cout << -1 << endl;
        else
            cout << cost[a][b] << endl;
    }

    return 0;
}
