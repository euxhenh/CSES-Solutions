#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int arr[110], n, x, md = 1e9 + 7, mx = -1;
int sol[1000100];
ll total;

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) mx = max(mx, arr[i]);
    sol[0] = 1;

    for (int i = 1; i < mx; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= arr[j]) sol[i] = (sol[i] + sol[i - arr[j]]) % md;
        }
    }
    // fast
    for (int i = mx; i <= x; ++i) {
        total = 0;
        for (int j = 0; j < n; ++j) {
            total += sol[i - arr[j]];
        }
        sol[i] = total % md;
    }
    cout << sol[x] << endl;

    return 0;
}
