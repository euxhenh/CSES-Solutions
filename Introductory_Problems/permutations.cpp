#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
    } else if (n == 4) {
        cout << "2 4 1 3\n";
    } else if (n == 3 || n == 2) {
        cout << "NO SOLUTION\n";
    } else {
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
