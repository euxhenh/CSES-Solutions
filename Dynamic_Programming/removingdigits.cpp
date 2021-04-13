#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int n, num, numcp, ans = INT_MAX;
    cin >> n;
    int dp[1000100];
    num = n;
    dp[0] = 0;
    for (int i = 1; i <= 9; ++i) dp[i] = 1;

    for (int i = 10; i <= n; ++i) {
        ans = INT_MAX;
        numcp = i;
        while (numcp > 0) {
            if (numcp % 10 != 0) ans = min(ans, 1 + dp[i - numcp % 10]);
            numcp /= 10;
        }
        dp[i] = ans;
    }
    cout << dp[n] << endl;
    return 0;
}
