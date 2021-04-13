#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <class T>
T lower_bound(T (*gen)(T), T l, T r, T key) {
    T mid, value;
    while (l < r) {
        mid = l + (r - l) / 2;
        value = gen(mid);

        if (value > key)
            l = mid + 1;
        else
            r = mid;
    }
    if (gen(r) <= key) return r;
    return -1;
}

ll n, arr[200200], k, mid;

ll func(ll val) {
    ll subarrays = 0, subtotal = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > val) return LLONG_MAX;
        subtotal += arr[i];
        if (subtotal > val) {
            ++subarrays;
            subtotal = arr[i];
        }
    }
    ++subarrays;
    return subarrays;
}

int main() {
    ll total = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i], total += arr[i];

    cout << lower_bound(&func, (ll)0, total, k) << endl;

    return 0;
}
