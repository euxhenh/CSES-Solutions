#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int N = 100100;
int n, m, ord[N];
vector<vector<int>> ad(N);
bool visited[N]{};
vector<int> s;

void dfs(int x) {
    if (visited[x]) return;
    visited[x] = 1;

    for (int i = 0; i < ad[x].size(); ++i) dfs(ad[x][i]);
    s.push_back(x);
}

int main() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b, --a, --b;
        ad[a].push_back(b);
    }

    for (int i = 0; i < n; ++i)
        if (!visited[i]) dfs(i);

    int oo = 0;
    reverse(s.begin(), s.end());
    for (auto v : s) ord[v] = oo++;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < ad[i].size(); ++j) {
            if (ord[i] > ord[ad[i][j]]) {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
    }
    for (auto v : s) cout << v + 1 << " ";

    return 0;
}
