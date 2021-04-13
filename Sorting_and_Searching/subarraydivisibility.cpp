#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, num;
    cin >> n;
    map<ll, ll> m;
    m[0] = 1;
    ll total = 0, sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        sum += num;
        sum %= n;
        if (sum < 0) sum += n;
        if (m.find(sum) != m.end()) {
            total += m[sum];
            m[sum]++;
        } else
            m[sum] = 1;
    }

    cout << total << endl;

    return 0;
}
