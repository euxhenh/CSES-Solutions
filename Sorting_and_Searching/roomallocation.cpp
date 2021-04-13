#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool comp(tuple<int, int, bool, int> t1, tuple<int, int, bool, int> t2) {
    if (get<0>(t1) < get<0>(t2))
        return true;
    else if (get<0>(t1) == get<0>(t2) && get<2>(t1) != get<2>(t2))
        return get<2>(t1);
    else
        return false;
}

int main() {
    int n, a, b, ord = 0, roomn = -1;
    cin >> n;
    vector<tuple<int, int, bool, int>> v;
    vector<ll> rooms(n);
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v.push_back(make_tuple(a, b, true, i));
        v.push_back(make_tuple(b, a, false, i));
    }

    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < 2 * n; ++i) {
        ord += (get<2>(v[i]) ? 1 : -1);
        roomn = max(roomn, ord);
    }

    for (int i = 0; i < roomn; ++i) q.push(i + 1);

    cout << roomn << endl;
    for (int i = 0; i < 2 * n; ++i) {
        if (get<2>(v[i])) {
            rooms[get<3>(v[i])] = q.front();
            q.pop();
        } else {
            q.push(rooms[get<3>(v[i])]);
        }
    }

    for (int i = 0; i < n; ++i) cout << rooms[i] << " ";
    return 0;
}
