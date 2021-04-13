#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, num, res = 0, subres = 0, loc, lastloc = -1;
    map<ll, int> m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (m.find(num) != m.end()) {
            loc = m[num];
            lastloc = max(lastloc, loc);
            subres = i - lastloc;
        } else {
            subres += 1;
        }
        res = max(res, subres);
        m[num] = i;
    }
    res = max(res, subres);
    cout << res << endl;

    return 0;
}
