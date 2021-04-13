#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const ll M = 1e9 + 7;

ll fast_pow(ll base, ll power, ll mod) {
    ll result = 1;
    while (power > 0) {
        if (power & 1 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    ll n, m;
    cin >> n >> m;
    ll total = 0;
    for (ll i = 0; i < n; ++i) {
        total = (total + fast_pow(m, gcd(i, n), M)) % M;
    }
    cout << (total * fast_pow(n, M - 2, M)) % M << endl;
    return 0;
}
