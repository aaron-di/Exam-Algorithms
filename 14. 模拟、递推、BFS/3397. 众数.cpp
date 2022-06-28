#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int s[6][10];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (n--) {
        int x;
        scanf("%d", &x);
        for (int i = 0; i < m; i++) {
            s[i][x % 10]++;
            x /= 10;
        }
    }

    for (int i = 0; i < m; i++) {
        int k = 0; 
        for (int j = 0; j < 10; j++) {
            if (s[i][k] < s[i][j]) {
                k = j;
            }
        }
        printf("%d\n", k); 
    }

    return 0;
}