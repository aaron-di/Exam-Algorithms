#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef long long LL;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            LL x = 0;
            while (i < s.size() && isdigit(s[i])) {
                x = x * 10 + s[i] - '0';
                if (x > INT_MAX) {
                    puts("-1");
                    return 0;
                }
                i++;
            }

            cout << x << endl;
            return 0;
        }
    }

    puts("-1");
    return 0;
}