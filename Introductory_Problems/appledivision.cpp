#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll best(int i, ll arr[], int n, ll sum1, ll sum2) {
    if (i == n - 1) {
        return min(abs(sum1 + arr[i] - sum2), abs(sum2 + arr[i] - sum1));
    } else {
        return min(best(i + 1, arr, n, sum1 + arr[i], sum2),
                   best(i + 1, arr, n, sum1, sum2 + arr[i]));
    }
}

int main() {
    int n;
    cin >> n;
    ll arr[30];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);

    cout << best(0, arr, n, 0, 0) << endl;

    return 0;
}
