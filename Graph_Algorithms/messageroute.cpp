#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

vector<vector<int>> v;
int dp[100100], path[100100];

int main() {
    int n, m, a, b, val;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) v.push_back(vector<int>());
    for (int i = 0; i < n; ++i) dp[i] = -1;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    queue<int> q;
    q.push(n - 1);
    dp[n - 1] = 0;

    while (q.size() > 0) {
        val = q.front();
        for (int i = 0; i < v[val].size(); ++i) {
            if (dp[v[val][i]] != -1) continue;
            dp[v[val][i]] = dp[val] + 1;
            path[v[val][i]] = val;
            q.push(v[val][i]);
        }
        q.pop();
    }
    if (dp[0] == -1)
        cout << "IMPOSSIBLE\n";
    else {
        cout << dp[0] + 1 << endl;
        int i = 0;
        cout << 1 << " ";
        while (i < n - 1) {
            cout << path[i] + 1 << " ";
            i = path[i];
        }
    }
    return 0;
}
