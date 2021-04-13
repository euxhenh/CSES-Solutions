#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int N = 2550;
ll n, m, comp = 0, comps[N], u, v, w, V, parent[N];
vector<vector<ar<ll, 2>>> ad(N);
vector<vector<ll>> vc, ff(N);
vector<vector<ar<ll, 3>>> ec;
bool visited[N];
ll dist[N];

void reach(ll x) {
    if (visited[x]) return;
    visited[x] = 1;
    comps[x] = comp;
    for (int i = 0; i < ff[x].size(); ++i) {
        reach(ff[x][i]);
    }
}

void bf(ll cc) {
    V = vc[cc].size();
    fill(dist, dist + n, 1e15);
    fill(parent, parent + n, -1);
    dist[vc[cc][0]] = 0;

    for (int _ = 0; _ < V - 1; ++_) {
        for (int i = 0; i < ec[cc].size(); ++i) {
            u = ec[cc][i][0], v = ec[cc][i][1], w = ec[cc][i][2];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < ec[cc].size(); ++i) {
        u = ec[cc][i][0], v = ec[cc][i][1], w = ec[cc][i][2];
        if (dist[u] + w < dist[v] && dist[u] < 1e15) {
            vector<ll> ord;
            int iter = v;
            set<ll> s;
            cout << "YES\n";
            while (s.find(parent[iter]) == s.end()) {
                ord.push_back(iter + 1);
                iter = parent[iter];
                s.insert(iter);
            }
            ord.push_back(iter + 1);
            ord.push_back(parent[iter] + 1);
            cout << ord[ord.size() - 1] << " ";
            for (int j = ord.size() - 2; ord[j] != parent[iter] + 1; --j)
                cout << ord[j] << " ";
            cout << parent[iter] + 1;
            exit(0);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c, --a, --b;
        ad[a].push_back({b, c});
        ff[a].push_back(b);
        ff[b].push_back(a);
    }
    fill(comps, comps + n, -1);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            reach(i);
            ++comp;
        }
    }
    for (int i = 0; i < comp; ++i) {
        vc.push_back(vector<ll>());
        ec.push_back(vector<ar<ll, 3>>());
    }
    for (int i = 0; i < n; ++i) {
        vc[comps[i]].push_back(i);
        for (int j = 0; j < ad[i].size(); ++j)
            ec[comps[i]].push_back({i, ad[i][j][0], ad[i][j][1]});
    }

    for (int i = 0; i < comp; ++i) bf(i);
    cout << "NO\n";
    return 0;
}
