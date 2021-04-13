#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int N = 100100;
int n, m, maxc = -1, x, sol[N]{}, from[N]{}, par;
vector<vector<int>> ad(N), parents(N);
vector<int> s;
bool visited[N]{};

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
        parents[b].push_back(a);
    }

    fill(sol, sol + n, -1);
    for (int i = 0; i < n; ++i)
        if (!visited[i]) dfs(i);

    reverse(s.begin(), s.end());
    sol[n - 1] = 0;

    for (int i = s.size() - 1; i >= 0; --i) {
        for (int j = 0; j < ad[s[i]].size(); ++j) {
            par = ad[s[i]][j];
            if (sol[s[i]] < sol[par] + 1 && sol[par] != -1) {
                sol[s[i]] = sol[par] + 1;
                from[s[i]] = par;
            }
        }
    }

    if (sol[0] == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << sol[0] + 1 << endl;
        for (int v = 0; v < n - 1; v = from[v]) cout << v + 1 << " ";
        cout << n;
    }

    return 0;
}
