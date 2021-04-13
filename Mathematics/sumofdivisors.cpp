#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    ll n, v1, v2, md, nums, M = 1e9 + 7, mm;
    cin >> n;

    ll total = 0;
    v2 = n + 1;
    for (ll i = 1; i * i <= n; ++i) {
        v1 = v2 - 1;
        v2 = n / (i + 1) + 1;
        if (v2 > v1) break;
        md = n % v1;
        nums = v1 - v2 + 1;
        mm = min(v1, v2);
        ll s1 = ((nums % M) * (md % M)) % M;
        ll s2 =
            ((((((nums % M) * ((nums - 1) % M)) % M) * i) % M) * 500000004) % M;
        total = (total + s1 + s2) % M;
        if (total < 0) cout << total << endl;
    }
    for (ll i = 1; i < mm; ++i) total = (total + n % i) % M;
    ll res = (((n % M) * (n % M)) % M - total) % M;
    while (res < 0) res += M;
    cout << res << endl;

    return 0;
}
