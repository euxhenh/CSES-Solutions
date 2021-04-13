#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

typedef vector<double> vi;
typedef vector<vector<double>> vvi;
vvi matmul(const vvi &v1, const vvi &v2) {
    vvi v3(v1.size(), vi(v2[0].size()));

    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v2[0].size(); ++j) {
            for (int k = 0; k < v1[0].size(); ++k) {
                v3[i][j] += v1[i][k] * v2[k][j];
            }
        }
    }
    return v3;
}

vvi fast_pow(vvi base, ll power) {
    vvi result = vvi(base.size(), vi(base[0].size()));
    for (int i = 0; i < 64; ++i) result[i][i] = 1;
    while (power > 0) {
        if (power & 1 == 1) result = matmul(result, base);
        base = matmul(base, base);
        power >>= 1;
    }
    return result;
}

pair<int, int> unroll(int k) {
    int i = k / 8;
    int j = k % 8;
    return {i, j};
}

double get_prob(int m, int n) {
    // from m to n
    auto p1 = unroll(m);
    auto p2 = unroll(n);

    double pos = 4;
    if (p1.first == 0 || p1.first == 7) --pos;
    if (p1.second == 0 || p1.second == 7) --pos;

    if (p1.first == p2.first) {
        if (abs(p1.second - p2.second) == 1)
            return 1.0 / pos;
        else
            return 0;
    } else if (p1.second == p2.second) {
        if (abs(p1.first - p2.first) == 1) return 1.0 / pos;
    }
    return 0;
}

int main() {
    int k;
    cin >> k;

    vvi markov(64, vi(64));
    for (int i = 0; i < 64; ++i)
        for (int j = 0; j < 64; ++j) markov[i][j] = get_prob(i, j);

    vvi res = fast_pow(markov, k);

    vvi filled(1, vi(64));
    for (int i = 0; i < 64; ++i) filled[0][i] = 1;

    for (int i = 0; i < 64; ++i) {
        vvi robot(1, vi(64));
        robot[0][i] = 1;
        vvi res2 = matmul(robot, res);
        for (int j = 0; j < 64; ++j) filled[0][j] *= (1 - res2[0][j]);
    }
    double total = 0;
    for (int i = 0; i < 64; ++i) total += filled[0][i];
    printf("%.6f", total);

    return 0;
}
