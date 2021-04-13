//not solved yet
#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int N = 100100;
int n, m, k;
vector<vector<ar<int, 2>>> v(N);

int main() {
    cin >> n >> m >> k;
    for (int i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c, --a, --b;
        v[a].push_back({b, c});
    }
    return 0;
}
