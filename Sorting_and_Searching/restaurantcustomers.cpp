#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, a, b;
    cin >> n;
    vector<pair<ll, bool>> p;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        p.push_back(make_pair(a, true));
        p.push_back(make_pair(b, false));
    }
    sort(p.begin(), p.end());
    ll total = 0, ans = -1;

    for (int i = 0; i < 2 * n; ++i) {
        if (p[i].second == true) {
            ++total;
            ans = max(ans, total);
        } else {
            --total;
        }
    }
    cout << ans << endl;
    return 0;
}
