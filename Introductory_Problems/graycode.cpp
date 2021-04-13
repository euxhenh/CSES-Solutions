#include <bits/stdc++.h>
#define ll long long
using namespace std;

char get(int row, int col) {
    // col starts at 0
    int p2m = pow(2, col);
    int p2M = pow(2, col + 2);
    int rem = row % p2M;
    if (rem < p2m || rem >= p2M - p2m) return '0';
    return '1';
}

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) s += '0';
    cout << s << endl;
    for (int i = 1; i < pow(2, n); ++i) {
        for (int j = 0; j < n; ++j) s[j] = get(i, j);
        cout << s << endl;
    }
    return 0;
}
