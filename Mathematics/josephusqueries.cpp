// not solved yet
#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int main() {
    int q, n, k, toskip;
    cin >> q;
    while (q--) {
        cin >> n >> k;
        if (n < 3) continue;
        ll first = 2, ord = 2, last = n - n % 2;
        ll rem = n;
        set<int> start, end;
        for (int i = 1; i <= log2(n); ++i) start.insert(i);
        for (int i = n - log2(n); i <= n; ++i) end.insert(i);
        start.erase(2);
        end.erase(2);
        start.erase(last);
        end.erase(last);

        printf("first %d and last %d\n", first, *end.rbegin());
        while (first + ord * (k - 1) > *end.rbegin()) {
            toskip = (n - 1) / ord;
            while (first + toskip * ord > *end.rbegin()) --toskip;
            last = first + toskip * ord;
            auto it = end.find(last);
            ++it;
            if (it == end.end()) {
                auto ut = start.begin();
                ++ut;
                first = *ut;
            } else
                first = *start.begin();

            printf("first %d and last %d\n", first, *end.rbegin());
            end.erase(last);
            start.erase(last);
            end.erase(first);
            start.erase(first);

            k -= toskip;
            ord *= 2;
        }
        cout << first + ord * (k - 1) << endl;
    }
    return 0;
}

/*
1:  1
2:  2 1
3:  2 1 3
4:  2 4 3 1
5:  2 4 1 5 3
6:  2 4 6 3 1 5
7:  2 4 6 1 5 3 7
8:  2 4 6 8 3 7 5 1
9:  2 4 6 8 1 5 9 7 3
10: 2 4 6 8 10 3 7 1 9 5
11: 2 4 6 8 10 1 5 9 3 11 7
12: 2 4 6 8 10 12 3 7 11 5 1 9
13: 2 4 6 8 10 12 1 5 9 13 7 3 11
14: 2 4 6 8 10 12 14 3 7 11 1 9 5 13
15: 2 4 6 8 10 12 14 1 5 9 13 3 11 7 15
16: 2 4 6 8 10 12 14 16 3 7 11 15 5 13 9 1
17: 2 4 6 8 10 12 14 16 1 5 9 13 17 7 15 11 3
18: 2 4 6 8 10 12 14 16 18 3 7 11 15 1 9 17 13 5
19: 2 4 6 8 10 12 14 16 18 1 5 9 13 17 3 11 19 15 7
20: 2 4 6 8 10 12 14 16 18 20 3 7 11 15 19 5 13 1 17 9
 * */
