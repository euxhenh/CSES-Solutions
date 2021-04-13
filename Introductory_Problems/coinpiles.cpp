#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        ll tn = 2 * a - b;
        if (tn >= 0 && tn % 3 == 0 && a - 2 * tn / 3 >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
