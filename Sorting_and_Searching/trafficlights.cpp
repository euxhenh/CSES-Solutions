#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll x, n, p, start, end;
    cin >> x >> n;
    multiset<ll> lens;
    set<ll> splits;

    splits.insert(0);
    splits.insert(x);
    lens.insert(x);

    for (int i = 0; i < n; ++i) {
        cin >> p;
        auto res = splits.insert(p);
        auto it = res.first;
        --it;
        start = *it;
        ++it;
        ++it;
        end = *it;

        lens.erase(lens.find(end - start));
        lens.insert(p - start);
        lens.insert(end - p);

        cout << *lens.rbegin() << " ";
    }
    return 0;
}
