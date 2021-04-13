#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    string s;
    cin >> s;
    int counter = 0, cur = 1;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1])
            ++cur;
        else {
            counter = max(counter, cur);
            cur = 1;
        }
    }
    counter = max(counter, cur);
    cout << counter << endl;
    return 0;
}
