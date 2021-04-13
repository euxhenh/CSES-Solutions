#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T>
std::vector<size_t> argsort(const std::vector<T> &array) {
    std::vector<size_t> indices(array.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(),
              [&array](int left, int right) -> bool {
                  return array[left] < array[right];
              });

    return indices;
}

int main() {
    int n;
    ll num;
    vector<ll> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        v.push_back(num);
    }
    auto indices = argsort(v);
    ll total = 1;
    for (int i = 1; i < n; ++i) {
        if (indices[i] < indices[i-1]) ++total;
    }
    cout << total << endl;
    return 0;
}
