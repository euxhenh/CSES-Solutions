#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int M = 1e9 + 7;
const int M2m = 500000004;

ll fast_pow(ll base, ll power, ll mod) {
    ll result = 1;
    while (power > 0) {
        if (power & 1 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}

ll fact(ll n) {
    ll prod = 1;
    for (ll i = 1; i <= n; ++i) prod = (prod * i) % M;
    return prod;
}

ll nchoosek(ll n, ll k) {
    ll prod = 1, prod2 = 1;
    for (ll i = n; i > n - k; --i) prod = (prod * i) % M;
    for (ll i = 1; i <= k; ++i) prod2 = (prod2 * i) % M;
    return (prod * fast_pow(prod2, M - 2, M)) % M;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int giv_start = 0, giv_end = 0;
    for (int i = 0; i < s.length(); ++i) {
        giv_start += (s[i] == '(');
        giv_end += (s[i] == ')');
        if (giv_start < giv_end) {
            cout << 0;
            return 0;
        }
    }

    if (n % 2 || giv_start > n / 2) {
        cout << 0;
        return 0;
    }

    int rem_start = n / 2 - giv_start;
    int rem_end = n / 2 - giv_end;

    ll c1 = nchoosek(2 * rem_start + giv_start - giv_end, rem_start);
    ll c2 = nchoosek(2 * rem_start + giv_start - giv_end, rem_start - 1);
    ll res = (c1 - c2) % M;
    if (res < 0) res += M;
    if (res == 0) res = 1;

    cout << res << endl;

    return 0;
}
