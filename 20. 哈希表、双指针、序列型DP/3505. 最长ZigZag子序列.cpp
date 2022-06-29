#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 55;

int n;
int w[N];
int f[N], g[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i];

    int res = 0;
    for (int i = 0; i < n; i++) {
        f[i] = g[i] = 1;
        for (int j = 0; j < i; j++) {
            if (w[j] > w[i]) f[i] = max(f[i], g[j] + 1);
            else if (w[j] < w[i]) g[i] = max(g[i], f[j] + 1);
        }
        res = max(res, max(f[i], g[i]));
    }

    cout << res << endl;

    return 0;
}