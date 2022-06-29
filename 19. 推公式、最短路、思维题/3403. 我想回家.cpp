#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 610, M = 20010, INF = 0x3f3f3f3f;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int q[N], dist1[N], dist2[N];
bool st[N];
int team[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa(int start, int dist[]) {
    memset(dist, 0x3f, sizeof dist1);
    dist[start] = 0;

    queue<int> q;
    q.push(start);
    st[start] = true;

    while (q.size()) {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (team[j] != start) continue;
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main() {
    while (scanf("%d", &n), n) {
        scanf("%d", &m);
        memset(h, -1, sizeof h), idx = 0;

        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c), add(b, a, c);
        }

        for (int i = 1; i <= n; i++) scanf("%d", &team[i]);

        spfa(1, dist1);
        spfa(2, dist2);

        int res = INF;
        for (int i = 0; i < idx; i++) {
            int a = e[i ^ 1], b = e[i];
            if (team[a] == 1 && team[b] == 2) {
                res = min(res, dist1[a] + w[i] + dist2[b]);
            }
        }

        if (res == INF) puts("-1");
        else cout << res << endl;
    }

    return 0;
}