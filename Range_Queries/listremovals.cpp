#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n, m, arr[200200], x, y, k, u, sig, r;

struct Node {
    ll val;
    int m, M;
    Node *left = NULL, *right = NULL;
    Node(){};
    Node(ll val_, int m_, int M_) {
        val = val_;
        m = m_;
        M = M_;
    }
};

Node *getnode(int m, int M) { return new Node((M + m) / 2 - m + 1, m, M); }

void construct(Node *node) {
    if (node->m == node->M) return;
    node->left = getnode(node->m, (node->M + node->m) / 2);
    node->right = getnode((node->M + node->m) / 2 + 1, node->M);
    construct(node->left);
    construct(node->right);
}

int update(Node *node, int i) {
    if (node->m == node->M) {
        node->val = -1;
        return arr[node->m];
    }

    if (i <= (node->val)) {
        (node->val)--;
        return update(node->left, i);
    } else {
        return update(node->right, i - node->val);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    Node *node = getnode(0, n - 1);
    construct(node);

    for (int i = 0; i < n; ++i) {
        cin >> r;
        int res = update(node, r);
        cout << res << " ";
    }
    return 0;
}
