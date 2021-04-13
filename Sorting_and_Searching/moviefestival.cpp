#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    ll total = 0, end = -1;
    bool watching = false;
    for (int i = 0; i < n; ++i) {
        if (end <= v[i].second) {
            watching = false;
        }
        if (!watching) {
            end = v[i].first;
            watching = true;
            ++total;
        }
    }
    cout << total << endl;
    return 0;
}
