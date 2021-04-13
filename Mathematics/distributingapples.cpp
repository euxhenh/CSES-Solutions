#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int M = 1e9 + 7;

ll facts[2000000 + 10];

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

int main() {
    int n, m;
    ll prod = 1;
    for (int i = 1; i <= 2 * 1e6; ++i) {
        prod = (prod * i) % M;
        facts[i] = prod;
    }

    cin >> n >> m;
    cout << (((facts[n + m - 1] * modinv(facts[n - 1], M)) % M) *
             modinv(facts[m], M)) %
                M;

    return 0;
}
