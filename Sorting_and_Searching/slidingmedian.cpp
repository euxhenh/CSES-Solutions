#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, arr[200200], k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    multiset<int> s;
    for (int i = 0; i < k; ++i) s.insert(arr[i]);
    multiset<int>::iterator it = s.begin();
    for (int i = 1; i < (k + 1) / 2; ++i) ++it;
    cout << *it;

    for (int i = k; i < n; ++i) {
        if (arr[i] == arr[i - k]) {
            cout << " " << *it;
            continue;
        } else if (arr[i] == *it) {  // arr[i-k] != arr[i]
            s.insert(it, arr[i]);
            if (arr[i] < arr[i - k]) --it;
        } else if (arr[i - k] == *it) {
            s.insert(arr[i]);
            if (arr[i] > *it)
                ++it;
            else
                --it;
        } else {
            s.insert(arr[i]);
            if (arr[i] < *it && arr[i - k] > *it)
                --it;
            else if (arr[i] > *it && arr[i - k] < *it)
                ++it;
        }
        s.erase(s.lower_bound(arr[i - k]));
        cout << " " << *it;
    }

    return 0;
}
