#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int M = 1e9 + 7;

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

int main() {
    ll n;
    cin >> n;
    ll total = fast_pow(2, n * n, M);
    if (n % 2 == 0) {
        total = (total + 2 * fast_pow(2, n * n / 4, M)) % M;
        total = (total + fast_pow(2, n * n / 2, M)) % M;
    } else {
        n /= 2;
        total = (total + 4 * fast_pow(2, n * (n + 1), M)) % M;
        total = (total + 2 * fast_pow(2, 2 * n * (n + 1), M)) % M;
    }
    total = (total * fast_pow(4, M - 2, M)) % M;
    cout << total;

    return 0;
}
