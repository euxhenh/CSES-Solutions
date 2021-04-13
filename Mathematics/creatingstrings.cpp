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

int main() {
    string s;
    ll prod = 1;
    for (int i = 1; i <= 1000000; ++i) {
        prod = (prod * i) % M;
        facts[i] = prod;
    }
    cin >> s;
    int chars[123]{};
    for (int i = 0; i < s.length(); ++i) chars[s[i]]++;

    ll total = facts[s.length()];
    for (int i = 0; i < 123; ++i) {
        if (chars[i] > 1) {
            total = (total * modinv(facts[chars[i]], M)) % M;
        }
    }
    cout << total << endl;
    return 0;
}
