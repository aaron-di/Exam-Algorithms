#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n, m;

int main() {
    unordered_set<int> S;

    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        S.insert(x);
    }
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        if (S.count(x)) puts("YES");
        else puts("NO");
    }

    return 0;
}