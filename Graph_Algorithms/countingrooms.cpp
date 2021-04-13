#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

vector<vector<int>> g;
bool visited[1000 * 1000];

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        if (!visited[g[v][i]]) {
            dfs(g[v][i]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    string b[1010], s;
    b[0] = b[n + 1] = "";
    for (int i = 0; i < m + 2; ++i) b[0] += '#', b[n + 1] += '#';

    for (int i = 1; i <= n; ++i) {
        cin >> s;
        s = '#' + s + '#';
        b[i] = s;
    }

    for (int i = 0; i < n * m; ++i) {
        vector<int> temp;
        g.push_back(temp);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (b[i][j] == '#') continue;
            if (b[i - 1][j] == '.')
                g[(i - 1) * m + j - 1].push_back((i - 2) * m + j - 1);
            if (b[i][j - 1] == '.')
                g[(i - 1) * m + j - 1].push_back((i - 1) * m + j - 2);
            if (b[i + 1][j] == '.')
                g[(i - 1) * m + j - 1].push_back(i * m + j - 1);
            if (b[i][j + 1] == '.')
                g[(i - 1) * m + j - 1].push_back((i - 1) * m + j);
        }
    }

    fill(visited, visited + n * m, 0);

    int total = 0;
    for (int i = 0; i < n * m; ++i) {
        if (!visited[i] && b[i / m + 1][i % m + 1] == '.') {
            ++total;
            dfs(i);
        }
    }
    cout << total << endl;

    return 0;
}
