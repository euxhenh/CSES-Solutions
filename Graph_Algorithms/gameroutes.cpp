#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int N = 100100, M = 1e9 + 7;
int n, m, sol[N]{}, x;
vector<vector<int>> ad(N);
bool visited[N]{};
vector<int> s;

void dfs(int x) {
    if (visited[x]) return;
    visited[x] = true;

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

    reverse(s.begin(), s.end());

    queue<int> q;
    sol[0] = 1;
    q.push(0);

    int k = 0;
    while (s[k] != 0) ++k;

    for (int i = k; i < s.size(); ++i) {
        x = s[i];
        for (int j = 0; j < ad[x].size(); ++j) {
            sol[ad[x][j]] = (sol[ad[x][j]] + sol[x]) % M;
            q.push(ad[x][j]);
        }
    }

    cout << sol[n - 1];

    return 0;
}
