#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const ll M = 1e9 + 7, mN = 1e6;

int main() {
    ll n, t, line[mN + 100], noline[mN + 100], m = 2;
    line[1] = 1;
    noline[1] = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        if (line[n] == 0) {
            for (; m <= n; ++m) {
                line[m] = (4 * line[m - 1] + noline[m - 1]) % M;
                noline[m] = (2 * noline[m - 1] + line[m - 1]) % M;
            }
        }
        cout << (line[n] + noline[n]) % M << endl;
    }
    return 0;
}
