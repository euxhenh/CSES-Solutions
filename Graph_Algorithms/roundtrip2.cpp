#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int N = 100100;
int n, m;
vector<vector<int>> ad(N);
bool visited[N]{}, done[N]{};
stack<int> q;

void dfs(int x) {
    if (done[x]) return;
    if (visited[x]) {
        vector<int> toprint;
        toprint.push_back(x);
        while (!q.empty() && q.top() != x) {
            toprint.push_back(q.top());
            q.pop();
        }
        toprint.push_back(x);
        reverse(toprint.begin(), toprint.end());
        cout << toprint.size() << endl;
        for (auto c : toprint) cout << c + 1 << " ";
        exit(0);
    }
    visited[x] = 1;
    q.push(x);
    for (int i = 0; i < ad[x].size(); ++i) dfs(ad[x][i]);
    q.pop();
    visited[x] = 0;
    done[x] = 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b, --a, --b;
        ad[a].push_back(b);
    }

    for (int i = 0; i < n; ++i) {
        if (!done[i]) dfs(i);
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}
