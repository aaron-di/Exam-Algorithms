#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int n;
int h[N];

int find(int x) {
    int t = (x % N + N) % N;

    while (h[t] != null && h[t] != x) {
        t = (t + 1) % N;
    }

    return t;
}

int main() {
    memset(h, 0x3f, sizeof h);
    scanf("%d", &n);
    while (n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (op[0] == 'I') {
            h[find(x)] = x;
        } else {
            if (h[find(x)] == null) puts("No");
            else puts("Yes");
        }
    }

    return 0;
}