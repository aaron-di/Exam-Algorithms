#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;

    while (m--) {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "M") {
            if (find(a) == find(b)) continue;
            else p[find(a)] = find(b);
        } else {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
}