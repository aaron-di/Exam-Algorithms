#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int w[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i];

    sort(w, w + n);

    int s1 = 0, s2 = 0;
    for (int i = 0; i < n / 2; i++) s1 += w[i];
    for (int i = n / 2; i < n; i++) s2 += w[i];

    printf("%d %d\n", n % 2, s2 - s1);

    return 0; 
}