#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

vector<vector<int>> v(200200);
bool visited[200200]{};

int main() {
    int n;
    cin >> n;
    for (int i = 0, a, b; i < n - 1; ++i) {
        cin >> a >> b, --a, --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    int len = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && v[i].size() == 1) {
            if (!visited[v[i][0]]) {
                ++len;
                visited[v[i][0]] = 1;
                visited[i] = 1;
                for (int j = 0; j < v[v[i][0]].size(); ++j) {
                    if (!visited[v[v[i][0]][j]]) {
                        q.push(v[v[i][0]][j]);
                    }
                }
            }
        }
    }
    return 0;
}
