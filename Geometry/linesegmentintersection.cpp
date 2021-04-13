#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

bool eq(double n1, double n2) { return abs(n1 - n2) < 1e-8; }
bool ge(double n1, double n2) { return n1 > n2 - 1e-8; }
bool le(double n1, double n2) { return n1 < n2 + 1e-8; }
double mmin(double n1, double n2, double n3, double n4) {
    return min(n1, min(n2, min(n3, n4)));
}

int main() {
    ll t, x1, y1, x2, y2, x3, y3, x4, y4;
    double k1, k2, x, yans1, yans2;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        // scanf("%lld %lld %lld %lld %lld %lld %lld %lld", x1, y1, x2, y2, x3,
        // y3,
        //       x4, y4);
        k1 = (double)(y2 - y1) / (x2 - x1);
        k2 = (double)(y4 - y3) / (x4 - x3);
        printf("%f %f\n", k1, k2);
        if (!eq(k1, k2)) {
            x = (double)(k2 * x3 - k1 * x1 + y1 - y3) / (k2 - k1);
            if (ge(x, min(x1, x2)) && le(x, max(x1, x2))) {
                if (ge(x, min(x3, x4)) && le(x, max(x3, x4)))
                    printf("YES\n");
                else
                    printf("NO\n");
            } else
                printf("NO\n");
        } else {
            double boo = max(min(x1, x2), min(x3, x4));
            if (le(boo, min(max(x1, x2), max(x3, x4))))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
