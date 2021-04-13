#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, t, arr[200200];
    cin >> n >> t;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    ll mn = t * arr[0], l = 0, r = mn, mid, total = 0;

    while (l < r) {
        mid = l + (r - l) / 2;
        total = 0;
        for (int i = 0; i < n; ++i) total += mid / arr[i];

        if (total >= t)
            r = mid;
        else
            l = mid + 1;
    }

    cout << r << endl;

    return 0;
}
