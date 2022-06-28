#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
    string a, b;
    cin >> a >> b;

    LL res = 0;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            int x = a[i] - '0';
            int y = b[j] - '0';

            res += x * y;
        }
    }

    cout << res << endl;

    return 0;
}