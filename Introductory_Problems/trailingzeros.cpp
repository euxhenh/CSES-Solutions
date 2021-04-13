#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, i = 5, trail = 0;
    cin >> n;

    while (n >= i) {
        trail += n / i;
        i *= 5;
    }

    cout << trail << endl;
    return 0;
}
