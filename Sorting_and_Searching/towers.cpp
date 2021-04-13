#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    ll num;
    cin >> n;
    multiset<ll> s;
    cin >> num;
    s.insert(num);

    for (int i = 1; i < n; ++i) {
        cin >> num;
        auto it = s.upper_bound(num);
        if (it != s.end()) s.erase(it);
        s.insert(num);
    }
    cout << s.size() << endl;
    return 0;
}
