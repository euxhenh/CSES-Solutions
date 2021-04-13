#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int n, q, arr[200200], a, b;
    ll sums[200200];
    cin >> n >> q;
    cin >> arr[0], sums[0] = arr[0];
    for (int i = 1; i < n; ++i) cin >> arr[i], sums[i] = sums[i - 1] ^ arr[i];
    while (q--) {
        cin >> a >> b, --a, --b;
        if (a == 0)
            cout << sums[b] << endl;
        else
            cout << (sums[b] ^ sums[a - 1]) << endl;
    }
    return 0;
}
