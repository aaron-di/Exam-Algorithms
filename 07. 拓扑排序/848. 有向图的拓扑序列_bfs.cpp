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
int d[N]; // 存储每个点的入度
int q[N]; // 数组模拟队列

void add(int a, int b) {
    auto p = new Node(b);
    p->next = head[a];
    head[a] = p;
}

bool topsort() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            q[++tt] = i;
        }
    }

    while (hh <= tt) {
        int t = q[hh++];
        for (auto p = head[t]; p; p = p->next) {
            if (--d[p->id] == 0) {
                q[++tt] = p->id;
            }
        }
    }

    return tt == n - 1;
}

int main() {
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        d[b]++;
        add(a, b);
    }

    if (!topsort()) puts("-1");
    else {
        for (int i = 0; i < n; i++) {
            printf("%d ", q[i]);
        }
    }

    return 0;
}