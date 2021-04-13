#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    ll t, x1, y1, x2, y2, x3, y3, i, j, k;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        k = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

        if (k == 0) printf("TOUCH\n");
        else if (k > 0) printf("LEFT\n");
        else printf("RIGHT\n");
    }
    return 0;
}
