#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        double h;
        int n;
        cin >> h >> n;

        double res = h;
        for (int i = 0; i < n - 1; i++) {
            res += h;
            h /= 2;
        }

        printf("%.2lf\n", res);
    }
}