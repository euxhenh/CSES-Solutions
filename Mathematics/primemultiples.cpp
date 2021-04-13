#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int i = 0, j = 0, k;
    ll n, p, total = 0, totals[22]{}, kk, prod = 1;
    vector<ll> v;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> p;
        v.push_back(p);
    }

    for (ll pp = 1; pp < pow(2, k); ++pp) {
        kk = pp;
        i = 0, j = 0;
        prod = 1;
        while (kk) {
            if (kk & 1 == 1) {
                if (log(prod) + log(v[j]) > 18 * log(10))
                    prod = (ll)1e18 + 1;
                else {
                    prod *= v[j];
                    ++i;
                }
            }
            ++j;
            kk >>= 1;
        }
        totals[i] += (n / prod);
    }

    bool op = 1;
    for (int i = 1; i <= k; ++i) {
        if (op)
            total += totals[i];
        else
            total -= totals[i];
        op = !op;
    }

    cout << total << endl;
    return 0;
}
