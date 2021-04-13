#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<char>> fill(vector<vector<char>> v, int m, int n) {
    for (int i = 0; i < 8; ++i) v[m][i] = '*', v[i][n] = '*';
    int cm = m, cn = n;
    while (min(cm, cn) >= 0) {
        v[cm][cn] = '*';
        --cm;
        --cn;
    }
    cm = m, cn = n;
    while (max(cm, cn) < 8) {
        v[cm][cn] = '*';
        ++cm;
        ++cn;
    }
    cm = m, cn = n;
    while (cm < 8 && cn >= 0) {
        v[cm][cn] = '*';
        ++cm;
        --cn;
    }
    cm = m, cn = n;
    while (cm >= 0 && cn < 8) {
        v[cm][cn] = '*';
        --cm;
        ++cn;
    }
    return v;
}

ll solve(int k, vector<vector<char>> board) {
    if (k == 7) {
        for (int i = 0; i < 8; ++i)
            if (board[k][i] != '*') return 1;
        return 0;
    }

    ll total = 0;

    for (int i = 0; i < 8; ++i) {
        if (board[k][i] != '*') {
            vector<vector<char>> v = fill(board, k, i);
            total += solve(k + 1, v);
        }
    }

    return total;
}

void printv(vector<vector<char>> v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

int main() {
    char c;
    vector<vector<char>> v;
    for (int i = 0; i < 8; ++i) {
        vector<char> tempv;
        for (int j = 0; j < 8; ++j) {
            cin >> c;
            tempv.push_back(c);
        }
        v.push_back(tempv);
    }
    cout << solve(0, v) << endl;
    return 0;
}
