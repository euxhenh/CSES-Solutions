#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n, q, salaries[200200], a, b, ans;
char c;

struct Node {
    int val, pos;
    Node *left = NULL, *right = NULL;
    Node();
    Node(int val_, int pos_) {
        val = val_;
        pos = pos_;
    }
};

Node *getNode(int m, int M) { return new Node((M + n) / 2 - m + 1, m, M); }

void construct(Node *node) {
    if (node->m == node->M) return;

}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> salaries[i];
    while (q--) {
        cin >> c >> a >> b;
        if (c == '!') --a;
        update(a, b);
        else {
            ans = count(a, b);
            printf("%d\n", ans);
        }
    }

    return 0;
}
