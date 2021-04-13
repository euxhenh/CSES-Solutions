#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int M = 1e9 + 7;

ll modinv(ll a, ll m) {
    ll m0 = m;
    ll y = 0, x = 1;

    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;

    return x;
}

ll nchoosek(ll n, ll k) {
    ll prod = 1, prod2 = 1;
    for (ll i = n; i > n - k; --i) prod = (prod * i) % M;
    for (ll i = 1; i <= k; ++i) prod2 = (prod2 * i) % M;
    return (prod * modinv(prod2, M)) % M;
}

int main() {
    int n;
    cin >> n;
    if (n % 2) {
        cout << 0;
        return 0;
    }
    ll res = (nchoosek(n, n / 2) * modinv(n / 2 + 1, M)) % M;
    cout << res;
    return 0;
}
