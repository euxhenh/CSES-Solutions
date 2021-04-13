#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

vector<vector<int>> divisors(200200);
int contained[1000100]{};

int main() {
    int n, arr[200200];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j * j <= arr[i]; ++j) {
            if (arr[i] % j == 0) {
                if (j * j < arr[i]) {
                    divisors[i].push_back(j);
                    divisors[i].push_back(arr[i] / j);
                } else {
                    divisors[i].push_back(j);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < divisors[i].size(); ++j) {
            ++contained[divisors[i][j]];
        }
    }

    for (int i = 1000000; i >= 1; --i) {
        if (contained[i] >= 2) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
