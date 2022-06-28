#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int l, m, n;
int a[N], b[N], c[N];

int main() {
    scanf("%d%d%d", &l, &m, &n);
    for (int i = 0; i < l; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);

    LL res = 1e18;
    for (int i = 0, j = 0, k = 0; i < l && j < m && k < n; ) {
        int x = a[i], y = b[j], z = c[k];
        res = min(res, (LL)(max(max(x, y), z) - min(min(x, y), z)));
        if (x <= y && x <= z) i++;
        else if (y <= x && y <= z) j++;
        else k++;
    }

    printf("%lld\n", res * 2);

    return 0;
}