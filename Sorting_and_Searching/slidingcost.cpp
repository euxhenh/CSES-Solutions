#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, arr[200200], k;
    ll cost = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    multiset<int> s;
    for (int i = 0; i < k; ++i) s.insert(arr[i]);
    multiset<int>::iterator it = s.begin();
    for (int i = 1; i < (k + 1) / 2; ++i) ++it;
    for (int i = 0; i < k; ++i) cost += abs(arr[i] - *it);
    cout << cost;
    int prev = *it;
    bool inc = false;

    for (int i = k; i < n; ++i) {
        inc = false;
        if (arr[i] == arr[i - k]) {
            cout << " " << cost;
            continue;
        } else if (arr[i] == *it) {  // arr[i-k] != arr[i]
            s.insert(it, arr[i]);
            if (arr[i] < arr[i - k]) --it;
        } else if (arr[i - k] == *it) {
            s.insert(arr[i]);
            if (arr[i] > *it)
                ++it, inc = true;
            else
                --it;
        } else {
            s.insert(arr[i]);
            if (arr[i] < *it && arr[i - k] > *it)
                --it;
            else if (arr[i] > *it && arr[i - k] < *it)
                ++it, inc = true;
        }
        s.erase(s.lower_bound(arr[i - k]));
        cost -= abs(arr[i - k] - prev);
        cost += abs(arr[i] - prev);

        if (k % 2 == 0) {
            if (inc)
                cost -= (*it - prev);
            else
                cost -= (*it - prev);
        }
        cost -= abs(*it - prev);

        if (inc) {
            cost -= ((k - 1) / 2) * (*it - prev);
            cost += ((k - 1) / 2) * (*it - prev);
        } else {
            cost += ((k - 1) / 2) * (*it - prev);
            cost -= ((k - 1) / 2) * (*it - prev);
        }

        cout << " " << cost;
        prev = *it;
    }

    return 0;
}
