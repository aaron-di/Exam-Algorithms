#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;

int n;
unordered_map<int, int> primes;

void divisor(int x) {
    primes.clear();
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) {
                x /= i;
                s++;
            }
            primes[i] = s;
        }
    }
    if (x > 1) primes[x] = 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        divisor(x);

        LL res = 1;
        for (auto it : primes) {
            res *= (it.second + 1);
        }
        cout << res << endl;
    }

    return 0;
}