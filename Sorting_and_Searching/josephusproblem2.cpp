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

    // k = k - ((k - 1) / n) * n;

    Node *node = getnode(0, n - 1);
    construct(node);

    int kk = k - ((k - 1) / n) * n;
    int nn = n, r = kk + 1, res;
    if (r > n) r -= n;
    for (int i = 0; i < n; ++i) {
        res = update(node, r);
        cout << res + 1 << " ";
        nn--;
        if (nn == 0) break;
        kk = k - ((k - 1) / nn) * nn;
        r = r + kk;
        while (r > nn) r -= nn;
        // r = r - ((r - 1) / nn) * nn;
    }
    return 0;
}
