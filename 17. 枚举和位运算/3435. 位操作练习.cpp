#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        string x, y;
        for (int i = 15; i >= 0; i--) {
            x += to_string(a >> i & 1);
            y += to_string(b >> i & 1);
        }
        y += y;
        if (y.find(x) != -1) puts("YES");
        else puts("NO");
    }

    return 0;
}