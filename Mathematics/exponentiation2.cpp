#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const ll M = 1e9 + 7;

ll fast_pow(ll a, ll b, ll mod) {
    ll res = a, total = 1;
    while (b > 0) {
        if (b & 1 == 1) total = (total * res) % mod;
        res = (res * res) % mod;
        b >>= 1;
    }
    return total;
}

int main() {
    ll n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        cout << fast_pow(a, fast_pow(b, c, M - 1), M) << endl;
    }
    return 0;
}
