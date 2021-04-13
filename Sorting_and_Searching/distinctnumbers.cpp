#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, num;
    cin >> n;
    set<ll> s;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        s.insert(num);
    }
    cout << s.size() << endl;
    return 0;
}
