#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int n, k, arr[100], dp[1000100]{};
    cin >> n >> k;
    for (int i = 0; i < k; ++i) scanf("%d", &arr[i]);
    for (int i = 0; i < k; ++i) dp[arr[i]] = 1;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] != 0) continue;
        for (int j = 0; j < k; ++j)
            if (arr[j] <= i) dp[i] = max((1 - dp[i - arr[j]]), dp[i]);
    }
    for (int i = 1; i <= n; ++i) cout << ((dp[i] == 1) ? "W" : "L");
    return 0;
}
