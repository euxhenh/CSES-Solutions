#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    ll arr[200200];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);

    ll result = 1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > result) break;
        result += arr[i];
    }
    cout << result << endl;
    return 0;
}
