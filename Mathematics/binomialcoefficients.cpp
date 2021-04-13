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

ll fact[1001000];

int main() {
    int n, a, b;
    ll prod = 1;
    for (ll i = 1; i <= 1000000; ++i) {
        prod = (prod * i) % M;
        fact[i] = prod;
    }
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << (((fact[a] * modinv(fact[b], M)) % M) *
                 modinv(fact[a - b], M)) %
                    M
             << endl;
    }
    return 0;
}
