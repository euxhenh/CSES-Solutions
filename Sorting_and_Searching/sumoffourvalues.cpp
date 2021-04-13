#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, t, s, to_look, a, ind1, ind2, ind3, ind4;
    vector<pair<int, int>> v;
    map<int, pair<int, int>> doublesums;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) cin >> a, v.push_back(make_pair(a, i + 1));
    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = v[i].first + v[j].first;
            doublesums[sum] = {v[i].second, v[j].second};
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = v[i].first + v[j].first;
            to_look = t - sum;
            auto it = doublesums.find(to_look);
            if (it != doublesums.end()) {
                ind1 = v[i].second;
                ind2 = v[j].second;
                ind3 = (*it).second.first;
                ind4 = (*it).second.second;
                if (ind3 != ind1 && ind3 != ind2 && ind4 != ind1 &&
                    ind4 != ind2) {
                    cout << ind1 << " " << ind2 << " " << ind3 << " " << ind4
                         << endl;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}

