#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010, M = 100010;

int n, m;
struct Node {
    int id;
    Node* next;
    Node(int _id): id(_id), next(NULL) {}
}*head[N];
int st[N], q[N], top;

void add(int a, int b) {
    auto p = new Node(b);
    p->next = head[a];
    head[a] = p;
}

bool dfs(int u) {
    st[u] = true;

    for (auto p = head[u]; p; p = p->next) {
        int j = p->id;
        if (!st[j]) {
            if (!dfs(j)) return false;
        } else if (st[j] == 1) {
            return false;
        }
    }

    q[top++] = u;

    st[u] = 2;
    return true;
}

bool topsort() {
    for (int i = 1; i <= n; i++) {
        if (!st[i] && !dfs(i)) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    if (!topsort()) puts("-1");
    else {
        for (int i = n - 1; i >= 0; i--) {
            printf("%d ", q[i]);
        }
    }

    return 0;
}