#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

ll n, m, a, b, c, x, val, par, toadd, score = 1e15;
vector<vector<ar<ll, 2>>> v(100100);
bool visited[100100]{};
multimap<ll, pair<ll, ll>> mm;

void dfs() {
    mm.insert(make_pair(0, make_pair(0, -1)));

    while (mm.size() > 0) {
        val = mm.begin()->first;
        x = (mm.begin()->second).first;
        par = (mm.begin()->second).second;
        mm.erase(mm.begin());
        if (visited[x]) continue;
        visited[x] = true;

        for (int i = 0; i < v[x].size(); ++i) {
            if (visited[v[x][i][0]] && v[x][i][0] != n - 1) continue;
            if (v[x][i][0] == n - 1) {
                if (par == -1)
                    toadd = v[x][i][1] / 2;
                else {
                    if (v[x][i][1] >= par)
                        toadd = v[x][i][1] / 2;
                    else
                        toadd = v[x][i][1] - (par + 1) / 2;
                }
                score = min(score, val + toadd);
            } else
                mm.insert(
                    make_pair(val + v[x][i][1],
                              make_pair(v[x][i][0], max(par, v[x][i][1]))));
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c, --a, --b;
        v[a].push_back({b, c});
    }
    dfs();
    cout << score;
    return 0;
}

