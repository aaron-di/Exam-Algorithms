#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, int> factors;
int n, a;

void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) {
                s++;
                x /= i;
            }
            factors[i] = s;
        }
    }
    if (x > 1) factors[x] = 1;
}

int get_p(int n, int p) {
    int res = 0;
    while (n / p) res += n / p, n /= p;
    return res;
}

int main() {
    cin >> n >> a;
    divide(a);

    int res = 0x3f3f3f3f;
    for (auto it: factors) {
        int p = it.first, c = it.second;
        res = min(res, (get_p(n, p) / c));
    }

    cout << res << endl;

    return 0;
}
