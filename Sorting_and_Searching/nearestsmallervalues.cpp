#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, arr[200200], m = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << 0 << " ";

    deque<pair<int, int>> dq;
    dq.push_back({arr[0], 1});

    for (int i = 1; i < n; ++i) {
        while (dq.size() > 0 && dq.back().first >= arr[i]) dq.pop_back();
        if (dq.size() > 0) cout << dq.back().second << " ";
        else cout << 0 << " ";
        dq.push_back({arr[i], i + 1});
    }

    return 0;
}
