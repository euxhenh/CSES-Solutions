#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;

        int total = 0;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                if (i * i == x) ++total;
                else total += 2;
            }
        }
        cout << total << endl;
    }

    return 0;
}
