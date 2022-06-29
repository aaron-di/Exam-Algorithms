#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        int res = 0;
        for (int i = 1; i * i * i <= n; i++) {
            int x = i * i * i;
            int r = sqrt(x);
            if (r * r == x) {
                res++;
            }
        }

        cout << res << endl;
    }

    return 0;
}