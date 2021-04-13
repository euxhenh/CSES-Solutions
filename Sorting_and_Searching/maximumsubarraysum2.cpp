#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    ll n, arr[200200], a, b, tillsum[200200];
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    ll sum = LLONG_MIN, subsum = 0;
    tillsum[0] = arr[0];
    multiset<ll> s;

    for (int i = 1; i < n; ++i) tillsum[i] = tillsum[i - 1] + arr[i];
    sum = tillsum[a - 1];

    for (int i = a; i < n; ++i) {
        s.insert(tillsum[i - a]);
        if (i >= b) s.erase(s.lower_bound(tillsum[i - b]));
        sum =
            max(sum, max(tillsum[i] - *s.begin(), tillsum[i] - tillsum[i - b]));
    }

    cout << sum << endl;

    return 0;
}
