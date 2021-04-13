#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int n, k, a, b, ans = 0;
    vector<ar<int, 2>> v;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());
    multiset<int> s;

    for (int i = 0; i < k; ++i) s.insert(0);

    for (int i = 0; i < n; ++i) {
        auto it = s.upper_bound(v[i][1]);
        if (it != s.end()) {
            if (*it > v[i][1]) {
                if (it != s.begin()) --it;
                else continue;
            }
        } else {
            if (s.size() > 0) --it;
            else continue;
        }

        if (*it <= v[i][1]) {
            ++ans;
            s.erase(it);
            s.insert(v[i][0]);
        }
    }

    cout << ans << endl;

    return 0;
}
