#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

bool dp[101 * 1001 + 10];

int main() {
    int n, arr[110], M = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    M = accumulate(arr, arr + n, M);

    dp[0] = 1;

    for (int j = 0; j < n; ++j) {
        for (int i = M; i; --i) {
            if (i >= arr[j] && dp[i - arr[j]]) {
                dp[i] = 1;
            }
        }
    }

    int total = 0;
    for (int i = 1; i <= M; ++i) total += dp[i];
    cout << total << endl;
    for (int i = 1; i <= M; ++i)
        if (dp[i] == 1) printf("%d ", i);

    return 0;
}
