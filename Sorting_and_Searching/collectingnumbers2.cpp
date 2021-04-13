#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T>
std::vector<int> argsort(const std::vector<T> &array) {
    std::vector<int> indices(array.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(),
              [&array](int left, int right) -> bool {
                  return array[left] < array[right];
              });

    return indices;
}

int context(vector<int> &indices, int x, int y) {
    int change_old = 0, change_new = 0;

    if (abs(x - y) == 1) {
        int qud[4] = {indices[min(x, y) - 1], indices[min(x, y)],
                      indices[max(x, y)], indices[max(x, y) + 1]};
        for (int i = 1; i < 4; ++i)
            if (qud[i] < qud[i - 1]) ++change_old;
        swap(qud[1], qud[2]);
        for (int i = 1; i < 4; ++i)
            if (qud[i] < qud[i - 1]) ++change_new;
    } else {
        int trip[3] = {indices[x - 1], indices[x], indices[x + 1]};
        for (int i = 1; i < 3; ++i)
            if (trip[i] < trip[i - 1]) ++change_old;
        int trip2[3] = {indices[y - 1], indices[y], indices[y + 1]};
        for (int i = 1; i < 3; ++i)
            if (trip2[i] < trip2[i - 1]) ++change_old;

        int trip3[3] = {indices[x - 1], indices[y], indices[x + 1]};
        for (int i = 1; i < 3; ++i)
            if (trip3[i] < trip3[i - 1]) ++change_new;
        int trip4[3] = {indices[y - 1], indices[x], indices[y + 1]};
        for (int i = 1; i < 3; ++i)
            if (trip4[i] < trip4[i - 1]) ++change_new;
    }
    return change_new - change_old;
}

int main() {
    vector<ll> v;
    int n, m, a, b;
    ll num;
    cin >> n >> m;
    v.push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        v.push_back(num);
    }
    v.push_back(n + 1);

    auto indices = argsort(v);
    ll total = 1;
    for (int i = 1; i <= n; ++i) {
        if (indices[i] < indices[i - 1]) ++total;
    }

    while (m--) {
        cin >> a >> b;
        total += context(indices, v[a], v[b]);
        swap(v[a], v[b]);
        swap(indices[v[a]], indices[v[b]]);
        cout << total << endl;
    }

    return 0;
}
