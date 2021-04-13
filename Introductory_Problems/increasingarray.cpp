#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, counter = 0, last, cur;
    cin >> n;
    cin >> last;
    for (int i = 1; i < n; ++i) {
        cin >> cur;
        if (cur < last) counter += (last - cur);
        last = max(last, cur);
    }

    cout << counter << endl;
    return 0;
}
