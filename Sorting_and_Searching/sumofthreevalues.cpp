#include <bits/stdc++.h>
#define ll long long
using namespace std;

int binarySearch(const vector<pair<int, int>>& v, int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m].first == x) return m;
        if (v[m].first < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    int n, t, s, to_look, a;
    vector<pair<int, int>> v;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) cin >> a, v.push_back(make_pair(a, i + 1));
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            s = v[i].first + v[j].first;
            to_look = t - s;
            int val = binarySearch(v, j + 1, n - 1, to_look);
            if (val != -1) {
                cout << v[i].second << " " << v[j].second << " "
                     << v[val].second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
