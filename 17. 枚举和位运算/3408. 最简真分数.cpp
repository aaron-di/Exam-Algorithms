#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 610;

int a[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    while (cin >> n, n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (gcd(a[i], a[j]) == 1) res++;
            }
        }

        cout << res << endl;
    }

    return 0;
}