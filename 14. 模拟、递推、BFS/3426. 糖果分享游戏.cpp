#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int q[N], w[N];

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) cin >> q[i];
        
        int cnt = 0;
        while (true) {
            bool is_same = true;
            for (int i = 1; i < n; i++) {
                if (q[i] != q[0]) {
                    is_same = false;
                    break;
                }
            }
            if (is_same) break;
            cnt++;
            for (int i = 0; i < n; i++) {
                w[i] = (q[i] + q[(i - 1 + n) % n]) / 2;
            }
            for (int i = 0; i < n; i++) {
                q[i] = w[i];
                if (q[i] % 2) q[i] ++;
            }
        }

        printf("%d %d\n", cnt, q[0]);
    }

    return 0;
}