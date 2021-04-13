#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const ll M = 1e9 + 7;

map<ll, ll> fibs;

ll fib(ll n) {
    auto it = fibs.find(n);
    if (it != fibs.end()) {
        return it->second;
    }
    ll m = n / 2, val, ff1, ff2;
    if (n % 2 == 0) {
        ff1 = fib(m + 1);
        ff2 = fib(m - 1);
        val = ((ff1 * ff1) % M) - ((ff2 * ff2) % M);
        val %= M;
        while (val < 0) val += M;
        val %= M;
        fibs[n] = val;
    } else {
        ff1 = fib(m + 2);
        ff2 = fib(m - 1);
        val = ((ff1 * ff1) % M) + ((ff2 * ff2) % M);
        val %= M;
        val *= 500000004;
        val %= M;
        fibs[n] = val;
    }
    return val;
}

int main() {
    ll n, prev = 0, temp, cur = 1;
    cin >> n;
    fibs[0] = 0;
    fibs[1] = 1;
    fibs[2] = 1;
    fibs[3] = 2;
    fibs[4] = 3;
    fibs[5] = 5;
    cout << fib(n) << endl;
    return 0;
}
