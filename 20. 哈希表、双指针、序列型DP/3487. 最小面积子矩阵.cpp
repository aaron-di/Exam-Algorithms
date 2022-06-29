#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n, m, k;
int s[N][N];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j];
        }
    }

    int res = INF;
    for (int x = 1; x <= n; x++) {
        for (int y = x; y <= n; y++) {
            for (int i = 1, j = 1, sum = 0; i <= m; i++) {
                sum += s[y][i] - s[x - 1][i];
                while (sum - (s[y][j] - s[x - 1][j]) >= k) {
                    sum -= s[y][j] - s[x - 1][j];
                    j++;
                }
                if (sum >= k) res = min(res, (y - x + 1) * (i - j + 1));
            }
        }
    }
    if (res == INF) res = -1;
    cout << res << endl;
    
    return 0;
}