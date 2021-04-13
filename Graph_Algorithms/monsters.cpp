#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n, m, ax, ay;
char lab[1010][1010], dir[1010][1010];
vector<ar<int, 2>> mon;
int mval[1010][1010], mvala[1010][1010];
bool visited[1010][1010], visiteda[1010][1010];
queue<ar<int, 3>> q;
stack<char> path;

bool canmove(int x, int y) { return mvala[x][y] < mval[x][y]; }
void solve(int x, int y);

void dome(int nx, int ny, char cc) {
    path.push(cc);
    solve(nx, ny);
    path.pop();
}

void solve(int x, int y) {
    if (!canmove(x, y)) return;
    if (x == ax && y == ay) {
        cout << "YES\n";
        cout << path.size() - 1 << endl;
        while (path.size() > 1) {
            cout << path.top();
            path.pop();
        }
        exit(0);
    }
    if (lab[x][y] == '#') return;
    if (visiteda[x][y]) return;
    visiteda[x][y] = true;
    dome(x + 1, y, 'U');
    dome(x - 1, y, 'D');
    dome(x, y + 1, 'L');
    dome(x, y - 1, 'R');
    visiteda[x][y] = false;
}

void fillm(bool a) {
    int x, y, val;
    if (!a)
        for (int i = 0; i < mon.size(); ++i) {
            x = mon[i][0], y = mon[i][1];
            q.push({x, y, 0});
        }
    else {
        q.push({ax, ay, 0});
    }

    int(*muse)[1010] = a ? mvala : mval;
    bool(*visiteduse)[1010] = a ? visiteda : visited;

    while (q.size() > 0) {
        x = q.front()[0], y = q.front()[1], val = q.front()[2];
        q.pop();
        if (lab[x][y] == '#') continue;
        if (visiteduse[x][y]) continue;
        visiteduse[x][y] = 1;
        muse[x][y] = val;
        q.push({x + 1, y, muse[x][y] + 1});
        q.push({x - 1, y, muse[x][y] + 1});
        q.push({x, y + 1, muse[x][y] + 1});
        q.push({x, y - 1, muse[x][y] + 1});
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n + 1; ++i) lab[i][0] = lab[i][m + 1] = '#';
    for (int i = 0; i <= m + 1; ++i) lab[0][i] = lab[n + 1][i] = '#';
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> lab[i][j];
            if (lab[i][j] == 'M')
                mon.push_back({i, j});
            else if (lab[i][j] == 'A')
                ax = i, ay = j;
            lab[i][j] = (lab[i][j] == '#') ? '#' : '.';
            mval[i][j] = mvala[i][j] = 1e7;
            visited[i][j] = visiteda[i][j] = 0;
            dir[i][j] = '.';
        }
    fillm(0);
    fillm(1);

    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j <= m + 1; ++j) visiteda[i][j] = 0;

    for (int i = 1; i <= n; ++i) {
        if (canmove(i, 1)) {
            path.push(dir[i][1]);
            solve(i, 1);
            path.pop();
        }
        if (canmove(i, m)) {
            path.push(dir[i][m]);
            solve(i, m);
            path.pop();
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (canmove(1, i)) {
            path.push(dir[1][i]);
            solve(1, i);
            path.pop();
        }
        if (canmove(n, i)) {
            path.push(dir[n][i]);
            solve(n, i);
            path.pop();
        }
    }
    cout << "NO\n";

    return 0;
}
