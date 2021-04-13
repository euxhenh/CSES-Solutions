#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int M = 1e9 + 7;

/*
0 = down, 1 = block
*/
int n, m;

bool compatible(const vector<int>& v1, const vector<int>& v2) {
    for (int i = 0; i < v1.size(); ++i)
        if (v1[i] == 1 && v2[i] == 1) return false;
    return true;
}

void to_row(int num, vector<int>& v) {
    int i = 0;
    while (num > 0) {
        v[i++] = num & 1;
        num >>= 1;
    }
    while (i < n) v[i++] = 0;
}

int legit(const vector<int>& v1, const vector<int>& v2) {
    int counter = 0;
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] == 1 || v2[i] == 1) {
            if (counter % 2 == 1) return 0;
            counter = 0;
        } else
            ++counter;
    }
    if (counter % 2 == 1) return 0;
    return 1;
}

int main() {
    string pths, iths;
    cin >> n >> m;
    vector<int> v1(n, 0), v2(n, 0);
    if (n % 2 == 1 && m % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    int pt = pow(2, n);

    // dp[m][2^n]
    ll dp[1030][1030]{};
    bool is_legit[1030][1030]{};
    bool is_compatible[1030][1030]{};
    for (int i = 0; i < pt; ++i) {
        to_row(i, v1);
        for (int j = 0; j < pt; ++j) {
            to_row(j, v2);
            is_legit[i][j] = legit(v1, v2);
            is_compatible[i][j] = compatible(v1, v2);
        }
    }

    for (int j = 0; j < pt; ++j) dp[0][j] = is_legit[0][j];
    for (int i = 1; i < m; ++i) {             // m
        for (int pth = 0; pth < pt; ++pth) {  // 2^(n-1)
            if (dp[i - 1][pth] == 0) continue;
            for (int ith = 0; ith < pt; ++ith) {  // 2^n
                if (is_compatible[pth][ith]) {
                    dp[i][ith] =
                        (dp[i][ith] + is_legit[pth][ith] * dp[i - 1][pth]) % M;
                }
            }
        }
    }
    cout << dp[m - 1][0];
    return 0;
}
