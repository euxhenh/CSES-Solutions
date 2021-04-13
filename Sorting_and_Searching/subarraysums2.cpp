#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, arr[200200], x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    ll total = 0, sum = 0;
    map<ll, ll> m;
    m[0] = 1;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (m.find(sum - x) != m.end()) total += m[sum - x];
        if (m.find(sum) != m.end())
            ++m[sum];
        else
            m[sum] = 1;
    }
    cout << total << endl;
    return 0;
}
