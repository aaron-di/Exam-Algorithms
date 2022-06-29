#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = 0;
        if (n >= 0) {
            res = (n + n * 2) * (n + 1) / 2;
        } else {
            res = (n + n * 2) * (n - 2 * n + 1) / 2;
        }
        cout << res << endl;
    }

    return 0;
}