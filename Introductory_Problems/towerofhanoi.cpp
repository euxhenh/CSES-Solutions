#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int n, int prevpos, int pos) {
    if (n == 1) {
        cout << prevpos << " " << pos << endl;
        return;
    }
    int topos = pos ^ prevpos;
    solve(n - 1, prevpos, topos);
    cout << prevpos << " " << pos << endl;
    solve(n - 1, topos, pos);
}

int main() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << endl;
    solve(n, 1, 3);

    return 0;
}
