#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, m, tickets[200200], temp;
    cin >> n >> m;

    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        s.insert(temp);
    }

    for (int i = 0; i < m; ++i) {
        cin >> temp;

        auto it = s.lower_bound(temp);
        if (it != s.end()) {
            if (*it > temp) {
                if (it != s.begin())
                    --it;
                else {
                    cout << -1 << endl;
                    continue;
                }
            }
            cout << *it << endl;
            s.erase(it);
        } else {
            if (s.size() > 0) {
                --it;
                cout << *it << endl;
                s.erase(it);
            } else
                cout << -1 << endl;
        }
    }

    return 0;
}
