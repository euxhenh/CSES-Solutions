#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

vector<int> primes;

void sieve() {
    int isprime[1010]{};
    fill(isprime + 2, isprime + 1000, 1);
    for (int i = 2; i * i <= 1000; ++i) {
        int j = 2 * i;
        while (j <= 1000) {
            isprime[j] = false;
            j += i;
        }
    }
    for (int i = 0; i <= 1000; ++i)
        if (isprime[i]) primes.push_back(i);
}

ll nchoose2(ll n) {
    if (n < 2) return 0;
    return (ll)n * (n - 1) / 2;
}

int main() {
    int n, arr[100100], M = -1;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i], M = max(M, arr[i]);
    sieve();

    int pf[1000100]{};

    for (int i = 0; i < n; ++i) {
        bool prime = 1;
        for (int j = 1; j * j <= arr[i]; ++j) {
            if (arr[i] % j == 0) {
                ++pf[j];
                if (j * j != arr[i]) ++pf[arr[i] / j];
            }
        }
    }

    ll total = nchoose2(n);
    for (int i = 2; i <= M; ++i) {
        bool flag = 0;
        int pp = 0;
        int kk = i;
        for (int j = 0; j < primes.size() && primes[j] <= kk; ++j) {
            if (kk % primes[j] == 0) {
                if (kk % (primes[j] * primes[j]) == 0) {
                    flag = 1;
                    break;
                }
                kk /= primes[j];
                ++pp;
                if (kk == 1) break;
            }
        }
        if (flag || pf[i] < 2) continue;
        if (kk > 1) ++pp;
        if (pp == 0) pp = 1;

        if (pp % 2)
            total -= nchoose2(pf[i]);
        else
            total += nchoose2(pf[i]);
    }
    cout << total << endl;

    return 0;
}
