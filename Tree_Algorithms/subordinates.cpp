#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n;

struct Node {
    int boss = -1, total = -1;
    vector<int> children;
};
Node emps[200200];

int subods(Node* node) {
    if (node->total != -1) return node->total;
    int total = 0;
    for (int i = 0; i < node->children.size(); ++i)
        total += subods(&(emps[node->children[i]]));
    total += node->children.size();
    node->total = total;
    return total;
}

int main() {
    cin >> n;
    for (int i = 1, emp; i < n; ++i) {
        cin >> emp, --emp;
        emps[i].boss = emp;
        emps[emp].children.push_back(i);
    }
    for (int i = 0; i < n; ++i) cout << subods(&emps[i]) << " ";

    return 0;
}
