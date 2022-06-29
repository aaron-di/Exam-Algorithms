#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (y != x && y != x - 2) puts("No Number");
        else if (y == x) {
            if (x % 2 == 0) cout << x * 2 << endl;
            else cout << x * 2 - 1 << endl;
        } else {
            if (x % 2 == 0) cout << x * 2 - 2 << endl;
            else cout << x * 2 - 3 << endl;
        }
    }

    return 0;
}