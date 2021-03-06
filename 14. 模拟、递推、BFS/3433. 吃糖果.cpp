#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 25;

int n;
int a[N];

int main() {
    cin >> n;
    a[0] = a[1] = 1;

    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[n] << endl;

    return 0;
}