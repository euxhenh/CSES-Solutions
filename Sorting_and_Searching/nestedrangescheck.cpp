#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct interval {
    int start, end, index;
    bool begin;
    interval() {}
    interval(int start_, int end_, int index_, bool begin_) {
        start = start_;
        end = end_;
        index = index_;
        begin = begin_;
    }
};

bool comp(interval i1, interval i2) {
    int v1 = i1.start, nv1 = i1.end;
    if (!i1.begin) swap(v1, nv1);
    int v2 = i2.start, nv2 = i2.end;
    if (!i2.begin) swap(v2, nv2);

    if (v1 < v2)
        return true;
    else if (v1 == v2 && i1.begin == i2.begin)
        return nv1 > nv2;
    else
        return false;
}

int main() {
    int n, a, b, bird1 = 0, bird2 = 0;
    cin >> n;
    int contained[200200], contains[200200];
    interval v[400400];
    fill(contained, contained + n, 0);
    fill(contains, contains + n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v[2 * i] = interval(a, b, i, true);
        v[2 * i + 1] = interval(a, b, i, false);
    }
    sort(v, v + 2 * n, comp);

    for (int i = 1; i < 2 * n; ++i) {
        if (!v[i].begin) {  // found interval endpoint
            if (v[i].index != v[bird1].index) {
                contained[v[i].index] = 1;
            } else {
                while (++bird1 < 2 * n)
                    if (v[bird1].begin && v[bird1].end > v[i].end) break;
            }

            while (v[bird2].start <= v[i].start && bird2 < i) {
                if (v[bird2].begin && v[bird2].index != v[i].index) {
                    if (v[bird2].end >= v[i].end &&
                        v[bird2].start <= v[i].start)
                        contains[v[bird2].index] = 1;
                }
                ++bird2;
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << contains[i] << " ";
    cout << endl;
    for (int i = 0; i < n; ++i) cout << contained[i] << " ";
    cout << endl;

    return 0;
}
