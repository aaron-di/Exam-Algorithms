#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 55, M = N * N / 2, INF = 0x3f3f3f3f;

int n, m, Q;
int g[N][N], d[N][N];
struct Edge {
    int a, b;
} e[M];

void floyd() {
    memcpy(d, g, sizeof g);

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> Q;
        memset(g, 0x3f, sizeof g);
        for (int i = 1; i <= n; i++) g[i][i] = 0;

        for (int i = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            e[i] = {a, b};
            g[a][b] = g[b][a] = c;
        }

        floyd();
        cout << d[1][n] << endl;

        while (Q--) {
            int t;
            cin >> t;
            int a = e[t].a, b = e[t].b;
            g[a][b] = g[b][a] = INF;
        }

        floyd();
        if (d[1][n] == INF) puts("-1");
        else cout << d[1][n] << endl;
    }

    return 0;
}