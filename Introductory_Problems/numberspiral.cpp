#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll t, x, y, num;
    cin >> t;
    while (t--) {
        cin >> x >> y;

        if (y <= x) {
            if (x % 2 == 0)
                num = x * x - y + 1;
            else
                num = (x - 1) * (x - 1) + y;
        } else {
            if (y % 2 == 1)
                num = y * y - x + 1;
            else
                num = (y - 1) * (y - 1) + x;
        }

        cout << num << endl;
    }
    return 0;
}
