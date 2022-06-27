#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200003;

int n;
int h[N], e[N], ne[N], idx;

void insert(int x) {
    int k = (x % N + N) % N;

    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x) {
    int k = (x % N + N) % N;

    for (int i = h[k]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == x) return true;
    }

    return false;
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d", &n);
    while (n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (op[0] == 'I') {
            insert(x);
        } else {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }
}