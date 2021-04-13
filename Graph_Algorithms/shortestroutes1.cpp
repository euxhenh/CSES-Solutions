#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

ll n, m, a, b, c, x, val;
vector<vector<ar<int, 2>>> v;
bool visited[100100];
ll sp[100100];
multimap<ll, int> mm;

void dfs() {
    mm.insert(make_pair(0, 0));

    while (mm.size() > 0) {
        x = mm.begin()->second;
        val = mm.begin()->first;
        mm.erase(mm.begin());
        if (visited[x]) continue;
        visited[x] = true;
        sp[x] = val;

        for (int i = 0; i < v[x].size(); ++i) {
            if (visited[v[x][i][0]]) continue;
            mm.insert(make_pair(sp[x] + v[x][i][1], v[x][i][0]));
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        vector<ar<int, 2>> temp;
        v.push_back(temp);
        sp[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        v[a - 1].push_back({b - 1, c});
    }
    dfs();
    for (int i = 0; i < n; ++i) cout << sp[i] << " ";
    return 0;
}
