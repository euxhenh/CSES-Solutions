#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    string s, t;
    cin >> s;
    int counts[123], odds = 0, oddone;
    for (int i = 0; i < 123; ++i) counts[i] = 0;
    for (char c : s) counts[c]++;
    for (int i = 'A'; i <= 'Z'; ++i) {
        if (counts[i] % 2 == 1) {
            ++odds;
            oddone = i;
        }
    }
    if (odds > 1)
        cout << "NO SOLUTION\n";
    else if (odds == 1) {
        for (int i = 'A'; i <= 'Z'; ++i) {
            if (i != oddone) {
                for (int j = 0; j < counts[i] / 2; ++j) t += i;
            }
        }
        for (int j = 0; j < counts[oddone] / 2; ++j) t += oddone;
        t += oddone;
        string cpt = t;
        reverse(cpt.begin(), cpt.end());
        t += cpt.substr(1);
        cout << t << endl;
    } else {
        for (int i = 'A'; i <= 'Z'; ++i) {
            for (int j = 0; j < counts[i] / 2; ++j) t += i;
        }
        string cpt = t;
        reverse(cpt.begin(), cpt.end());
        t += cpt;
        cout << t << endl;
    }
    return 0;
}
