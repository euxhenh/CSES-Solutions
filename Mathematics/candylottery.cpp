#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

double fast_pow(double base, ll power) {
    double result = 1;
    while (power > 0) {
        if (power & 1 == 1) result = (result * base);
        base = (base * base);
        power >>= 1;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    double res = 0;
    for (int i = 1; i <= k; ++i)
        res += fast_pow((double)i / k, n) * i -
               fast_pow((double)(i - 1) / k, n) * i;
    printf("%.6f", res);
    return 0;
}
