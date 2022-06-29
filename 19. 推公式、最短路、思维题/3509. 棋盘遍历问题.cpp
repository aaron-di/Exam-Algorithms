#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 1 && m == 1) puts("Y");
        else if (n % 2 && m % 2) puts("N");
        else if (n == 1 || m == 1) puts("N");
        else puts("Y");
    }

    return 0;
}