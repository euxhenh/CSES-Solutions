#include <bits/stdc++.h>
#define ll long long
using namespace std;

int factorial(int n) {
    int prod = 1;
    for (int i = 1; i <= n; ++i) prod *= i;
    return prod;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int chars[123];
    for (int i = 0; i < 123; ++i) chars[i] = 0;
    for (char c : s) chars[c]++;
    int total = factorial(n);
    for (int i = 0; i < 123; ++i)
        if (chars[i] > 1) total /= factorial(chars[i]);
    cout << total << endl;
    sort(s.begin(), s.end());
    cout << s << endl;
    set<string> myset;
    myset.insert(s);

    while (next_permutation(s.begin(), s.end())) {
        if (myset.find(s) == myset.end()) {
            myset.insert(s);
            cout << s << endl;
        }
    }
    return 0;
}
