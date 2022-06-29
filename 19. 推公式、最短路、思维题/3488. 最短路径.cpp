#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, MOD = 100000;

int n, m;
int p[N];
int d[N][N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) p[i] = i;

    memset(d, 0x3f, sizeof d);
    for (int i = 0; i < n; i++) d[i][i] = 0;

    for (int i = 0, len = 1; i < m; i++, len = len * 2 % MOD) {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b)) {
            p[find(a)] = find(b);
            d[a][b] = d[b][a] = len;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (d[0][i] == 0x3f3f3f3f) cout << -1 << endl;
        else cout << d[0][i] % MOD << endl;
    }

    return 0;
}