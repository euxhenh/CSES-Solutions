#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int n, x, arr[20], pp, rem;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int mm = 1 << n;
    pair<int, int> sol[mm];

    sol[0] = {1, 0};
    for (int i = 1; i < mm; ++i) {
        sol[i].first = 21;
        for (int p = 0; p < n; ++p) {
            pp = 1 << p;
            rem = i ^ pp;
            if (i & pp) {
                pair<int, int> prev = sol[rem];
                if ((ll)prev.second + arr[p] <= (ll)x) {
                    prev.second += arr[p];
                } else {
                    ++prev.first;
                    prev.second = arr[p];
                }
                sol[i] = min(sol[i], prev);
            }
        }
    }
    cout << sol[mm - 1].first;

    return 0;
}
