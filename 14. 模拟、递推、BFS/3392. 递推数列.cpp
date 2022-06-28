#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a, b, p, q, k;

int main() {
    cin >> a >> b >> p >> q >> k;
    int c = 0;
    for (int i = 2; i <= k; i++) {
        c = (p * b + q * a) % 10000;
        a = b, b = c;
    }

    cout << c % 10000 << endl;

    return 0;
}