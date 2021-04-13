#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, arr[200200], x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    ll total = 0, sum = 0, j = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        while (sum > x) sum -= arr[j++];
        if (sum == x) ++total;
    }
    cout << total << endl;
    return 0;
}
