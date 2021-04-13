#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

vector<vector<int>> v;
int team[100100];
bool visited[100100];

int main() {
    int n, m, a, b, val;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) v.push_back(vector<int>());
    for (int i = 0; i < n; ++i) team[i] = -1;
    for (int i = 0; i < n; ++i) visited[i] = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    stack<int> q;
    for (int i = n - 1; i >= 0; --i) q.push(i);
    team[0] = 0;

    while (q.size() > 0) {
        int i = q.top();
        q.pop();
        if (visited[i]) continue;
        visited[i] = 1;
        for (int j = 0; j < v[i].size(); ++j) {
            if (team[v[i][j]] != -1) {
                if (team[i] == -1)
                    team[i] = 1 - team[v[i][j]];
                else if (team[i] == team[v[i][j]]) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
        if (team[i] == -1) team[i] = 0;
        for (int j = 0; j < v[i].size(); ++j) {
            team[v[i][j]] = 1 - team[i];
            q.push(v[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) cout << team[i] + 1 << " ";

    return 0;
}
