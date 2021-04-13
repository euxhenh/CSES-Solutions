#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, k, num, j = 0;
    cin >> n >> k;
    map<ll, pair<ll, ll>> m;  // number: {first index, last index}
    queue<pair<ll, ll>> q;    // {number, index}
    ll total = 0;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        q.push({num, i});

        if (m.find(num) != m.end()) {
            total += i - q.front().second + 1;
            m[num] = {m[num].first, i};
        } else {
            if (m.size() == k) {
                ll fix_first = q.front().first;
                ll fix_second = m[fix_first].second;
                while (q.front().second <= fix_second) {
                    if (q.front().second == m[q.front().first].second) {
                        m.erase(q.front().first);
                        q.pop();
                        break;
                    } else
                        m[q.front().first] = {q.front().second,
                                              m[q.front().first].second};
                    q.pop();
                }
            }
            total += i - q.front().second + 1;
            m[num] = {i, i};
        }
    }

    cout << total << endl;

    return 0;
}
