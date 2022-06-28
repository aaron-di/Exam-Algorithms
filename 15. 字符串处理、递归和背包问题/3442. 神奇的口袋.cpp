#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50;

int n, m = 40;
int f[N];

int main() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        for (int j = m; j >= v; j--) {
            f[j] += f[j - v];
        }
    }
    cout << f[m] << endl;

    return 0;
}