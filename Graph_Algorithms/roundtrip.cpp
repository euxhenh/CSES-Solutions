#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

vector<vector<int>> v;
int stacklen[100100];
bool visited[100100];
stack<int> q;

void dfs(int x) {
    if (visited[x]) {
        if (q.size() - stacklen[x] >= 3) {
            cout << q.size() - stacklen[x] + 1 << endl;
            cout << x + 1 << " ";
            while (q.top() != x) {
                cout << q.top() + 1 << " ";
                q.pop();
            }
            cout << x + 1 << endl;
            exit(0);
        }
        return;
    }
    visited[x] = true;
    stacklen[x] = q.size();
    q.push(x);
    for (int j = 0; j < v[x].size(); ++j) dfs(v[x][j]);
    q.pop();
    stacklen[x] = -1;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        v.push_back(vector<int>());
        visited[i] = 0;
        stacklen[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfs(i);
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
