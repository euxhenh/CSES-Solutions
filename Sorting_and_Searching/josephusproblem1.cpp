#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct child {
    ll id;
    child *next, *prev;
};

int main() {
    int n;
    ll id;
    child children[200200];
    cin >> n;

    children[0].next = &children[1];
    children[0].prev = &children[n - 1];
    children[0].id = 0;

    children[n - 1].next = &children[0];
    children[n - 1].prev = &children[n - 2];
    children[n - 1].id = n - 1;

    for (int i = 1; i < n - 1; ++i) {
        children[i].next = &children[i + 1];
        children[i].prev = &children[i - 1];
        children[i].id = i;
    }

    int i = 0;
    child *toprint = &children[1];

    while (n--) {
        id = toprint->id;
        cout << id + 1 << " ";
        children[id].prev->next = children[id].next;
        children[id].next->prev = children[id].prev;
        toprint = children[id].next->next;
    }
    cout << endl;
    return 0;
}
