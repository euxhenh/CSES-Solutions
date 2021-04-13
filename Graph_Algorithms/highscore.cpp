#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n, m, ind, par;
vector<vector<int>> adj(2550), rev(2550);
ll cost[2550][2550], scores[2550], val;
bool visited[2550]{}, done[2550]{}, reachable[2550]{};

void reach(int x) {
    if (reachable[x]) return;
    reachable[x] = true;
    for (int i = 0; i < rev[x].size(); ++i) reach(rev[x][i]);
}

void dfs(int x, ll val) {
    if (!reachable[x]) return;

    if (visited[x]) {
        if (val - scores[x] > 0) {
            cout << -1;
            exit(0);
        }
        return;
    }
    if (scores[x] >= val) return;
    scores[x] = val;
    visited[x] = true;
    for (int i = 0; i < adj[x].size(); ++i)
        dfs(adj[x][i], val + cost[x][adj[x][i]]);
    visited[x] = false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) cost[i][j] = cost[j][i] = -1e15;
    for (int i = 0; i < n; ++i) scores[i] = -1e15;
    for (int i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back(b);
        rev[b].push_back(a);
        cost[a][b] = max((ll)c, cost[a][b]);
    }
    reach(n - 1);
    dfs(0, 0);
    cout << scores[n - 1];

    return 0;
}
