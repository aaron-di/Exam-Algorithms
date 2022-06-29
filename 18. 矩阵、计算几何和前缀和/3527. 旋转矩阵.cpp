#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;

vector<vector<int>> rotate(vector<vector<int>> a) {
    auto res = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < n; j++, k--) {
            res[i][j] = a[k][i];
        }
    }
    return res;
}

int main() {
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    auto b = a;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        if (a == b) {
            cout << i * 90 << endl;
            return 0;
        }
        a = rotate(a);
    }

    cout << -1 << endl;
    return 0;
}