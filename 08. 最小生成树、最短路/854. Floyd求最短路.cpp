#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;

int n, m, Q;
int d[N][N];

int main() {
    cin >> n >> m >> Q;
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j],  d[i][k] + d[k][j]);
            }
        }
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;
        int c = d[a][b];
        if (c > INF / 2) puts("impossible");
        else printf("%d\n", c);
    }

    return 0;
}