#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

char dpc[1010][1010];
int xa, ya, xb, yb, x, y, n, m, dpi[1010][1010];
char b[1010][1010], c;
bool visited[1010][1010];

void step(int a, int b, int na, int nb, char cc) {
    if (dpi[a][b] > dpi[na][nb] + 1) {
        dpi[a][b] = dpi[na][nb] + 1;
        dpc[a][b] = cc;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m + 2; ++i) b[0][i] = b[n + 1][i] = '#';
    for (int i = 0; i < n + 2; ++i) b[i][0] = b[i][m + 1] = '#';

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> c;
            if (c == 'A') xa = i, ya = j;
            if (c == 'B') xb = i, yb = j;
            b[i][j] = (c == '#') ? '#' : '.';
            dpi[i][j] = 1e7;
            dpc[i][j] = ' ';
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i <= n + 1; ++i) dpi[i][0] = dpi[i][m + 1] = 1e7;
    for (int j = 0; j <= m + 1; ++j) dpi[0][j] = dpi[n + 1][j] = 1e7;

    queue<ar<int, 2>> q;
    q.push({xb, yb});
    dpi[xb][yb] = 0;
    dpc[xb][yb] = ' ';

    while (q.size() > 0) {
        x = q.front()[0];
        y = q.front()[1];
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;

        if (b[x][y] == '#') continue;

        step(x, y, x - 1, y, 'U');
        step(x, y, x + 1, y, 'D');
        step(x, y, x, y - 1, 'L');
        step(x, y, x, y + 1, 'R');
        q.push({x - 1, y});
        q.push({x + 1, y});
        q.push({x, y - 1});
        q.push({x, y + 1});
    }

    if (dpc[xa][ya] == ' ')
        cout << "NO\n";
    else {
        cout << "YES\n";
        cout << dpi[xa][ya] << endl;
        while (xa != xb || ya != yb) {
            cout << dpc[xa][ya];
            if (dpc[xa][ya] == 'D')
                ++xa;
            else if (dpc[xa][ya] == 'U')
                --xa;
            else if (dpc[xa][ya] == 'L')
                --ya;
            else
                ++ya;
        }
    }

    return 0;
}
