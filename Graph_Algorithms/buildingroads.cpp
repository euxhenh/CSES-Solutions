#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n, m, cc = 0, a, b;
vector<vector<int>> v;
bool visited[100100];
vector<int> tolink;

void dfs(int x) {
    if (visited[x]) return;
    visited[x] = true;
    for (int i = 0; i < v[x].size(); ++i) dfs(v[x][i]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) v.push_back(vector<int>());
    for (int i = 0; i < n; ++i) visited[i] = false;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++cc;
            dfs(i);
            tolink.push_back(i + 1);
        }
    }

    cout << cc - 1 << endl;
    for (int i = 0; i < tolink.size() - 1; ++i)
        cout << tolink[i] << " " << tolink[i + 1] << endl;
    return 0;
}
