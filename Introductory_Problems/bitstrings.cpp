#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll rem = 1e9 + 7;

ll fast_pow(ll base, ll n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return base % rem;
    }

    if (n % 2 == 1) {
        ll cp = base;
        base *= base;
        base %= rem;
        return fast_pow(base, n / 2) * cp % rem;
    }
    base *= base;
    base %= rem;
    return fast_pow(base, n / 2);
}

int main() {
    int n;
    cin >> n;

    cout << fast_pow(2, n) << endl;

    return 0;
}
