#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int divide(int x) {
    int res = 0;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) {
                s++;
                x /= i;
            }
            res += s;
        }
    }
    if (x > 1)
        res++;

    return res;
}

int main() {
    int n;
    while (cin >> n) {
        cout << divide(n) << endl;
    }

    return 0;
}