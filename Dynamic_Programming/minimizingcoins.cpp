#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int sol[1000100], arr[110], mm, n, x, MM = 1e9 + 1;

int dp(int x) {
    if (x == 0)
        return 0;
    else if (x < mm) {
        sol[x] = MM;
        return MM;
    }

    if (sol[x] != 0) return sol[x];

    int ans = MM;

    for (int i = 0; i < n; ++i) {
        if (x < arr[i]) continue;
        if (sol[x - arr[i]] != 0)
            ans = min(ans, 1 + sol[x - arr[i]]);
        else
            ans = min(ans, 1 + dp(x - arr[i]));
    }
    sol[x] = ans;
    return ans;
}

int main() {
    mm = MM;
    cin >> n >> x;
    fill(sol, sol + 1000001, 0);
    for (int i = 0; i < n; ++i)
        cin >> arr[i], sol[arr[i]] = 1, mm = min(mm, arr[i]);

    sol[0] = 0;
    int ans = dp(x);
    if (ans == MM)
        cout << -1 << endl;
    else
        cout << dp(x) << endl;

    return 0;
}
