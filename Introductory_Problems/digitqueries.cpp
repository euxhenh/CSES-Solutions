#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int q;
    ll k;
    cin >> q;
    while (q--) {
        cin >> k;
        ll cur = 9;
        ll p = 1;
        ll last = 0;

        while (k > p * cur) {
            k -= p * cur;
            last += cur;
            cur *= 10;
            ++p;
        }
        ll num = last + (k + p - 1) / p;
        ll rem = k % p;
        if (rem == 0)
            num %= 10;
        else {
            string s = to_string(num);
            num = s[rem - 1] - '0';
        }
        cout << num << endl;
    }
    return 0;
}
