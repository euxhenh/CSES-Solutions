#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    char grid[1010][1010]{};
    int n, q, y1, x1, y2, x2, vals[1010][1010]{};
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> grid[i][j];

    for (int i = 1; i <= n; ++i) {
        int rowc = 0;
        for (int j = 1; j <= n; ++j) {
            rowc += (grid[i][j] == '*');
            vals[i][j] = vals[i - 1][j] + rowc;
        }
    }

    while (q--) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << vals[y2][x2] - vals[y1 - 1][x2] - vals[y2][x1 - 1] +
                    vals[y1 - 1][x1 - 1]
             << endl;
    }
    return 0;
}
