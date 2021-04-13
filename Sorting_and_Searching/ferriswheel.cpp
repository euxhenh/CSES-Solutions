#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, x, arr[200200], total = 0, beg = 0;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);

    for (int i = n - 1; i >= beg; --i) {
        if (i == beg) {
            ++total;
            continue;
        }
        if (arr[beg] + arr[i] <= x) {
            ++total;
            ++beg;
        } else {
            ++total;
        }
    }
    cout << total << endl;

    return 0;
}
