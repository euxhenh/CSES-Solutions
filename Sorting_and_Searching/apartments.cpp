#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, m, k, a[200200], b[200200];
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);

    ll i = 0, j = 0, total = 0;
    while (i < n && j < m) {
        if (b[j] > a[i] + k) {
            ++i;
        } else if (b[j] < a[i] - k) {
            ++j;
        } else {
            ++i;
            ++j;
            ++total;
        }
    }

    cout << total << endl;
    return 0;
}
