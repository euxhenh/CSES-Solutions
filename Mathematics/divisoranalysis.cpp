#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int M = 1e9 + 7;

ll fast_pow(ll base, ll power) {
    ll result = 1;
    while (power > 0) {
        if (power & 1 == 1) result = (result * base) % M;
        base = (base * base) % M;
        power = power >>= 1;
    }
    return result;
}

ll modInverse(ll a, ll m) {
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
    int n, a, b;
    ll divnum = 1, divsum = 1, divprod = 1, divnumm1 = 1, ptouse, ssprod;
    ll prodsf[100100], prodsr[100100], prods[100100];
    cin >> n;
    vector<ar<ll, 2>> v;
    while (n--) {
        cin >> a >> b;
        v.push_back({a, b});
        divnum = (divnum * (b + 1)) % M;
        divsum *= ((fast_pow(a, b + 1) - 1) * modInverse(a - 1, M)) % M;
        divsum %= M;
    }

    if (v.size() == 1) {
        ptouse = (v[0][1] * (v[0][1] + 1) / 2) % (M - 1);
        divprod = fast_pow(v[0][0], ptouse);
        cout << divnum << " " << divsum << " " << divprod;
        return 0;
    }

    prodsf[0] = v[0][1] + 1;
    prodsr[v.size() - 1] = v[v.size() - 1][1] + 1;
    for (int j = 1; j < v.size(); ++j)
        prodsf[j] = (prodsf[j - 1] * (v[j][1] + 1)) % (M - 1);
    for (int j = v.size() - 2; j >= 0; --j)
        prodsr[j] = (prodsr[j + 1] * (v[j][1] + 1)) % (M - 1);
    prods[0] = prodsr[1];
    prods[v.size() - 1] = prodsf[v.size() - 2];
    for (int j = 1; j < v.size() - 1; ++j)
        prods[j] = (prodsf[j - 1] * prodsr[j + 1]) % (M - 1);

    for (int i = 0; i < v.size(); ++i) {
        ptouse = prods[i];
        ssprod = ((v[i][1] * (v[i][1] + 1)) / 2) % (M - 1);
        ptouse = (ptouse * ssprod) % (M - 1);
        divprod = (divprod * fast_pow(v[i][0], ptouse)) % M;
    }
    cout << divnum << " " << divsum << " " << divprod;
    return 0;
}
