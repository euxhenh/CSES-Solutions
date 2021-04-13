#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

typedef vector<double> vi;
typedef vector<vector<double>> vvi;

double get_prob(int p, int q) {
    double prob = 0;
    for (int i = 1; i <= p; ++i) prob += (double)(min(i - 1, q)) / q;
    prob /= p;
    return prob;
}

int main() {
    int n, arr[110];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vvi markov(n, vi(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) markov[i][j] = get_prob(arr[i], arr[j]);
    double total = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j) total += markov[i][j];
    printf("%.6f", total);
    return 0;
}
