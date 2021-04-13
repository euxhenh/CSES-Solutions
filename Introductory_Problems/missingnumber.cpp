#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, arr[200200], t;
    cin >> n;
    for (int i = 0; i < n + 1; ++i) arr[i] = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> t;
        arr[t] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (arr[i] == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
