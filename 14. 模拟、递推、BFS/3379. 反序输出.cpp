#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        reverse(s.begin(), s.end());
        cout << s << endl;
    }

    return 0;
}