#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, arr[200200];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    if (n == 1) {
        cout << 2 * arr[0] << endl;
        return 0;
    }
    sort(arr, arr + n);
    ll i = 0, j = n - 1, rem1 = arr[0], rem2 = arr[n - 1];
    ll total = 0, subtotal1 = 0, subtotal2 = 0;

    while (i < n && j >= 0) {
        if (rem1 == 0) {
            ++i;
            if (i == j) {
                if (i == n - 1) {
                    total += rem2;
                    i = n;
                } else
                    ++i;
            }
            if (i != n) rem1 = arr[i];
        }
        if (rem2 == 0) {
            --j;
            if (i == j) {
                if (j == 0) {
                    total += rem1;
                    j = -1;
                } else
                    --j;
            }
            if (j != -1) rem2 = arr[j];
        }

        ll mm = min(rem1, rem2);
        rem1 -= mm;
        rem2 -= mm;
        total += mm;
    }

    total += max(rem1, rem2);
    while (++i < n) subtotal1 += arr[i];
    while (--j >= 0) subtotal2 += arr[j];
    cout << total + max(subtotal1, subtotal2) << endl;
    return 0;
}
