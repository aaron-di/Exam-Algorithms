#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 15;

int n, m;
int w[N][N];

// C = A * B
void mul(int c[][N], int a[][N], int b[][N]) {
     static int tmp[N][N];
     memset(tmp, 0, sizeof tmp);
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                tmp[i][j] += a[i][k] * b[k][j];
            }
        }
     }
    memcpy(c, tmp, sizeof tmp);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    int res[N][N] = {0};
    for (int i = 0; i < n; i++) res[i][i] = 1;

    while (m--) mul(res, res, w);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}