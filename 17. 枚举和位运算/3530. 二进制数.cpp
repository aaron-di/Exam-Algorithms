#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
    unsigned int n;
    while (cin >> n) {
        string x;
        if (n == 0) x = "0";
        while (n) x += to_string(n & 1), n >>= 1;
        reverse(x.begin(), x.end());

        cout << x << endl;
    }
    
    return 0;
}