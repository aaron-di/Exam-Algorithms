#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 1e5 + 10, INF = 0x3f3f3f3f;

int n, m;
int g[N][N], dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;

    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        if (dist[t] == INF) return INF;

        st[t] = true;
        res += dist[t];

        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], g[t][j]);
        }
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int res = prim();
    if (res == INF) puts("impossible");
    else printf("%d\n", res);

    return 0;
}