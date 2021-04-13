#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, a, b;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    ll total = 0, penalty = 0;
    for (int i = 0; i < n; ++i) {
        total += v[i].first;
        penalty += v[i].second - total;
    }
    cout << penalty << endl;
    return 0;
}
