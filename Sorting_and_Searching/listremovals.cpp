#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

int n, k;

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
        return node->m;
    }

    if (i <= (node->val)) {
        (node->val)--;
        return update(node->left, i);
    } else {
        return update(node->right, i - node->val);
    }
}

int main() {
    cin >> n >> k;

    Node *node = getnode(0, n - 1);
    construct(node);

    int nn = n, r = k + 1, res;
    for (int i = 0; i < n; ++i) {
        res = update(node, r);
        cout << res + 1 << " ";
        r = r + k;
        nn--;
        if (nn == 0) break;
        while (r > nn) {
            r -= nn;
        }
    }
    return 0;
}
