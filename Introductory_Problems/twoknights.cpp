#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, counter = 0;
    cin >> n;

    for (ll k = 1; k <= n; ++k) {
        if (k == 1)
            cout << 0 << endl;
        else if (k == 2)
            cout << 6 << endl;
        else if (k == 3)
            cout << 28 << endl;
        else {
            counter = (k - 4) * (k - 4) * (k * k - 9);
            counter += 4 * (k * k - 3);
            counter += 8 * (k * k - 4);
            counter += (4 * k - 16) * (k * k - 5);
            counter += 4 * (k * k - 5);
            counter += (4 * (k - 4)) * (k * k - 7);
            cout << counter / 2 << endl;
        }
    }

    return 0;
}
