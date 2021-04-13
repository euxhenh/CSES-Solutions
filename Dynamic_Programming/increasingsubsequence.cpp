#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int n, arr[200200], dp[200200];
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    m[0] = 0;

    for (int i = 0; i < n; ++i) {
        auto it = m.lower_bound(arr[i]);
        if (it == m.end()) {
            --it;
            m[arr[i]] = it->second + 1;
            continue;
        }

        auto ut = it;
        --ut;
        int M = ut->second + 1;
        if (it->first == arr[i]) {
            it->second = max(it->second, M);
            ++it;
        } else {
            m[arr[i]] = M;
        }
        auto k = it;
        for (; k != m.end(); ++k)
            if (k->second > M) break;

        m.erase(it, k);
    }

    int M = -1;
    for (auto i = m.begin(); i != m.end(); ++i) M = max(M, (i->second));
    cout << M << endl;
    return 0;
}
