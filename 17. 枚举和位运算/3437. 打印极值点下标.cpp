#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (a[i] != a[i + 1]) cout << i << " ";
        } else if (i == n - 1) {
            if (a[i - 1] != a[i]) cout << i << " ";
        } else {
            if (a[i - 1] < a[i] && a[i + 1] < a[i] || a[i - 1] > a[i] && a[i + 1] > a[i]) cout << i << " ";
        }
    }

    return 0;
}