#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

ll m = 1e9 + 7;
ll arr[1001000];

ll dp(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (arr[n] != 0)
        return arr[n] % m;
    else {
        for (int j = 1; j <= min(6, n); ++j) {
            arr[n] += dp(n - j);
            arr[n] %= m;
        }
        return arr[n] % m;
    }
}

int main() {
    int n;
    cin >> n;
    fill(arr, arr + n + 1, 0);
    arr[1] = 1;
    cout << dp(n) << endl;
    return 0;
}
