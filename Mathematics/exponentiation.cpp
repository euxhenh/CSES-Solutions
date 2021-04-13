#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int M = 1e9 + 7;

ll fast_pow(int a, int b) {
    ll res = a % M, total = 1;
    while (b > 0) {
        if (b & 1 == 1) total = (total * res) % M;
        res = (res * res) % M;
        b >>= 1;
    }
    return total;
}

int main() {
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << fast_pow(a, b) << endl;
    }
    return 0;
}
