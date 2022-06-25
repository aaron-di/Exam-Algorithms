#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n, m;
struct Edge {
    int a, b, c;
    bool operator< (const Edge& t) const {
        return c < t.c;
    }
}e[M];

int p[N];  // 并查集

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);

    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c);
    }
    sort(e, e + m);

    for (int i = 1; i <= n; i++) p[i] = i;

    int res = 0, cnt = n;
    for (int i = 0; i < m; i++) {
        int a = e[i].a, b = e[i].b, c = e[i].c;
        if (find(a) != find(b)) {
            res += c;
            cnt--;
            p[find(a)] = find(b);
        }
    }

    if (cnt > 1) puts("impossible");
    else printf("%d\n", res);

    return 0;
}