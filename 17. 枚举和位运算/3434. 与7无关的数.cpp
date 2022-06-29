#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

bool is_seven(int x) {
    if (x % 7 == 0) return true;
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }

    return false;
}

int main() {
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!is_seven(i)) {
            res += i * i;
        }
    }

    cout << res << endl;

    return 0;
}