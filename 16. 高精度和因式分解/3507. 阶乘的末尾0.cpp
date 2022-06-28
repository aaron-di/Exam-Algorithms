#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int res = 0;
    while (n / 5) res += n / 5, n /= 5;
    
    cout << res << endl;

    return 0;
}