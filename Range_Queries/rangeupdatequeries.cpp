#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n, q, arr[200200], x, y, k, u, sig;

struct Node {
    ll val = 0;
    int m, M;
    Node *left = NULL, *right = NULL;
    Node(){};
    Node(ll val_, int m_, int M_) {
        val = val_;
        m = m_;
        M = M_;
    }
};

Node *getnode(int m, int M) { return new Node(0, m, M); }

void construct(Node *node) {
    if (node->m == node->M) return;
    node->left = getnode(node->m, (node->M + node->m) / 2);
    node->right = getnode((node->M + node->m) / 2 + 1, node->M);
    construct(node->left);
    construct(node->right);
}

void update(Node *node, int a, int b, ll val) {
    if (node == NULL) return;
    if (node->m == a && node->M == b) {
        node->val += val;
        return;
    }
    if (b <= (node->left)->M)
        update(node->left, a, b, val);
    else if (a >= (node->right)->m)
        update(node->right, a, b, val);
    else {
        update(node->left, a, (node->left)->M, val);
        update(node->right, (node->right)->m, b, val);
    }
}

void print_node(Node *node) {
    if (node == NULL) return;
    printf("Node %d has range %d, %d\n", node->val, node->m, node->M);
    print_node(node->left);
    print_node(node->right);
}

ll solve(Node *node, int k) {
    if (node->m == k && node->M == k) return node->val;
    int b1 = (node->left)->m, e1 = (node->left)->M;
    int b2 = (node->right)->m, e2 = (node->right)->M;
    if (k <= e1)
        return node->val + solve(node->left, k);
    else
        return node->val + solve(node->right, k);
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    Node *node = getnode(0, n - 1);
    construct(node);

    while (q--) {
        cin >> sig;
        if (sig == 2) {
            cin >> k, --k;
            cout << solve(node, k) + arr[k] << endl;
        } else {
            cin >> x >> y >> u, --x, --y;
            update(node, x, y, u);
        }
    }
    return 0;
}
