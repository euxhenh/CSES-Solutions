#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    if (n * (n + 1) / 2 % 2 != 0)
        cout << "NO\n";
    else {
        ll m = n;
        ll arr[n + 100];
        for (int i = 0; i <= n; ++i) arr[i] = 0;
        ll sum = n * (n + 1) / 4;

        while (sum > 0) {
            if (sum > m) {
                arr[m] = 1;
                sum -= m;
                m -= 1;
            } else {
                arr[sum] = 1;
                sum = 0;
            }
        }

        if (sum < 0) {
            cout << "NO\n";
            return 0;
        }

        cout << "YES\n";

        ll f = 0;
        for (int i = 0; i <= n; ++i) f += arr[i];
        cout << f << endl;
        for (int i = 0; i <= n; ++i)
            if (arr[i] == 1) cout << i << " ";
        cout << endl;

        cout << n - f << endl;
        for (int i = 1; i <= n; ++i)
            if (arr[i] == 0) cout << i << " ";
        cout << endl;
    }
    return 0;
}
