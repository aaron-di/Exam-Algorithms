#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;

int n;
int g[N][N];

void rotate(int x, int y, int m) {
    int w[N][N]; 

    for (int i = 0; i < m; i++) {
        for (int j = 0, k = m - 1; j < m; j++, k--) {
            w[i][j] = g[x + k][y + i];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            g[x + i][y + j] = w[i][j];
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> g[i][j];
        }
    }

    int a, b, x, y;
    cin >> a >> b >> x >> y;
    x--, y--;

    if (a == 1) rotate(x, y, b);
    else {
        for (int i = 0; i < 3; i++) {
            rotate(x, y, b);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}