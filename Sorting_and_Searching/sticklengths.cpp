#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    ll arr[200200];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);

    ll best = 1e9 * n + 1;

    ll s1 = 0, s2 = 0, k;
    for (int i = 0; i < n; ++i) s2 += arr[i];

    for (int i = 0; i < n - 1; ++i) {
        s1 += arr[i];
        s2 -= arr[i];

        if (i + 1 >= (n - i - 1)) {
            k = arr[i];
        } else {
            k = arr[i + 1];
        }
        best = min(best, (i + 1) * k - s1 + s2 - (n - i - 1) * k);
    }

    cout << best << endl;

    return 0;
}
