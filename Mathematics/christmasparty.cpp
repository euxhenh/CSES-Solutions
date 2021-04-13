#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int M = 1e9 + 7;

ll facts[1000100];

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

ll nchoosek(int n, int k) {
    ll prod = facts[n];
    prod = (prod * modinv(facts[k], M)) % M;
    prod = (prod * modinv(facts[n - k], M)) % M;
    return prod;
}

int main() {
    int n;
    ll prod = 1;
    facts[0] = 1;
    for (int i = 1; i <= 1000000; ++i) {
        prod = (prod * i) % M;
        facts[i] = prod;
    }

    cin >> n;

    ll total = facts[n];

    bool op = true;
    for (int i = 1; i <= n; ++i) {
        if (op)
            total = total - (nchoosek(n, i) * facts[n - i]) % M;
        else
            total = total + (nchoosek(n, i) * facts[n - i]) % M;
        while (total < 0) total += M;
        op = !op;
    }

    cout << total % M << endl;
    return 0;
}
