#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n, q, arr[200200], x, y, k, u, sig;

struct Node {
    int val, m, M;
    Node *left = NULL, *right = NULL;
    Node(){};
    Node(int val_, int m_, int M_) {
        val = val_;
        m = m_;
        M = M_;
    }
};

Node *getnode(int m, int M) {
    int val = 1e9 + 1;
    for (int i = m; i <= M; ++i) val = min(val, arr[i]);
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
        node->val = val;
        return;
    }
    if (i <= (node->left)->M)
        update(node->left, i, val);
    else
        update(node->right, i, val);
    node->val = min((node->left)->val, (node->right)->val);
}

void print_node(Node *node) {
    if (node == NULL) return;
    printf("Node %d has range %d, %d\n", node->val, node->m, node->M);
    print_node(node->left);
    print_node(node->right);
}

int solve(Node *node, int a, int b) {
    if (node->m == a && node->M == b) return node->val;
    int mm = 1e9 + 1;
    int b1 = (node->left)->m, e1 = (node->left)->M;
    int b2 = (node->right)->m, e2 = (node->right)->M;
    if (b <= e1)
        return solve(node->left, a, b);
    else if (a >= b2)
        return solve(node->right, a, b);
    else
        return min(solve(node->left, a, e1), solve(node->right, b2, b));
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    Node *node = getnode(0, n - 1);
    construct(node);

    while (q--) {
        cin >> sig >> x >> y, --x;
        if (sig == 2) {
            --y;
            cout << solve(node, x, y) << endl;
        } else {
            update(node, x, y);
        }
    }
    return 0;
}
