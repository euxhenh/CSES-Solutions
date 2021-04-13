#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, x, val;
    vector<pair<ll, ll>> v;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        v.push_back(make_pair(val, i));
    }

    sort(v.begin(), v.end());

    int i = 0, j = n - 1;
    bool found = false;

    while (i < j) {
        if (v[i].first + v[j].first > x) {
            --j;
        } else if (v[i].first + v[j].first < x) {
            ++i;
        } else {
            cout << v[i].second + 1 << " " << v[j].second + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "IMPOSSIBLE" << endl;

    return 0;
}
