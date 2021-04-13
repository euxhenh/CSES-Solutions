#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    ll subsum = 0, bestsum = 0, val;
    cin >> subsum;
    bestsum = subsum;

    while (--n) {
        cin >> val;
        if (val >= 0 && subsum < 0)
            subsum = val;
        else if (subsum + val < 0) {
            bestsum = max(bestsum, subsum);
            subsum = val;
        } else {
            subsum += val;
            bestsum = max(bestsum, subsum);
        }
    }
    bestsum = max(bestsum, subsum);

    cout << bestsum << endl;

    return 0;
}
