#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10, MOD = 1e9;

int n;
int f[N];

int main() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i *= 2) {
        for (int j = i; j <= n; j++) {
            f[j] = (f[j] + f[j - i]) % MOD;
        }
    }
    cout << f[n] << endl;

    return 0;
}