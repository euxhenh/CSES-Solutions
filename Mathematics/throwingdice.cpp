#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

const int M = 1e9 + 7;

vector<vector<ll>> prod(vector<vector<ll>>& v1, vector<vector<ll>>& v2) {
    vector<vector<ll>> v(v1.size(), vector<ll>(v2[0].size()));
    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v2[0].size(); ++j) {
            for (int k = 0; k < v1[0].size(); ++k) {
                v[i][j] = (v[i][j] + v1[i][k] * v2[k][j]) % M;
            }
        }
    }
    return v;
}

vector<vector<ll>> fast_pow(vector<vector<ll>> base, ll power) {
    vector<vector<ll>> result(6, vector<ll>(6));
    for (int i = 0; i < 6; ++i) result[i][i] = 1;
    while (power > 0) {
        if (power & 1 == 1) result = prod(result, base);
        base = prod(base, base);
        power = power >>= 1;
    }
    return result;
}

int main() {
    ll n;
    cin >> n;

    vector<vector<ll>> s{{0, 0, 0, 0, 0, 1}};
    vector<vector<ll>> cm(6, vector<ll>(6));
    for (int i = 0; i < 5; ++i) cm[i + 1][i] = cm[i][5] = 1;
    cm[5][5] = 1;
    vector<vector<ll>> tm = fast_pow(cm, n);
    vector<vector<ll>> mm = prod(s, tm);
    cout << mm[0][5] << endl;
    return 0;
}
