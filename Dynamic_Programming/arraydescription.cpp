#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int mN = 1e5, M = 1e9 + 7;

int main() {
    int n, m, arr[mN], forward[mN][110], backward[mN][110], a, b, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m + 1; ++j) forward[i][j] = backward[i][j] = 0;

    if (arr[0] == 0)
        a = 1, b = m;
    else
        a = arr[0], b = arr[0];
    for (int j = a; j <= b; ++j) forward[0][j] = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] == 0)
            a = max(1, a - 1), b = min(m, b + 1);
        else
            a = arr[i], b = arr[i];

        for (int j = a; j <= b; ++j) forward[i][j] = 1;
    }

    if (arr[n - 1] == 0)
        a = 1, b = m;
    else
        a = arr[n - 1], b = arr[n - 1];
    for (int j = a; j <= b; ++j) backward[n - 1][j] = 1;

    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] == 0)
            a = max(1, a - 1), b = min(m, b + 1);
        else
            a = arr[i], b = arr[i];

        for (int j = a; j <= b; ++j) backward[i][j] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            forward[i][j] &= backward[i][j];
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (forward[i][j] == 1) {
                forward[i][j] = 0;
                forward[i][j] += forward[i - 1][j - 1];
                forward[i][j] %= M;
                forward[i][j] += forward[i - 1][j];
                forward[i][j] %= M;
                forward[i][j] += forward[i - 1][j + 1];
                forward[i][j] %= M;
            }
        }
    }

    for (int j = 1; j <= m; ++j) {
        ans = (ans + forward[n - 1][j]) % M;
    }

    cout << ans << endl;

    return 0;
}
