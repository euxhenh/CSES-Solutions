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

Node *getnode(int m, int M) {
    int val = 0;
    for (int i = m; i <= M; ++i) val = max(arr[i], val);
    return new Node(val, m, M);
}

void construct(Node *node) {
    if (node->m == node->M) return;
    node->left = getnode(node->m, (node->M + node->m) / 2);
    node->right = getnode((node->M + node->m) / 2 + 1, node->M);
    construct(node->left);
    construct(node->right);
}

void update(Node *node, int i, int val) {
    if (node == NULL) return;
    if (node->m == i && node->M == i) {
        node->val -= val;
        return;
    }
    if (i <= (node->left)->M)
        update(node->left, i, val);
    else
        update(node->right, i, val);
    node->val = max((node->left)->val, (node->right)->val);
}

void print_node(Node *node) {
    if (node == NULL) return;
    printf("Node %d has range %d, %d\n", node->val, node->m, node->M);
    print_node(node->left);
    print_node(node->right);
}

int solve(Node *node, int val) {
    if (node->val < val) return -1;
    if (node->left == NULL) return node->m;
    if ((node->left)->val >= val)
        return solve(node->left, val);
    else
        return solve(node->right, val);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    Node *node = getnode(0, n - 1);
    construct(node);

    while (m--) {
        cin >> r;
        int res = solve(node, r);
        if (res != -1) update(node, res, r);
        cout << res + 1 << endl;
    }
    return 0;
}
