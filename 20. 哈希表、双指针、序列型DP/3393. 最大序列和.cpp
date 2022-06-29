#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int n;

int main() {
    scanf("%d", &n);

    LL res = -1e18;
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        sum += x;
        res = max(res, sum);
        sum = max(0ll, sum);
    }

    printf("%lld", res);

    return 0;
}