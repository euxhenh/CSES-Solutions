#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int t, n, c, res = 0;
    cin >> t;
    while (t--) {
        scanf("%d", &n);
        res = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &c);
            res ^= c;
        }
        if (res == 0)
            printf("second\n");
        else
            printf("first\n");
    }
    return 0;
}
