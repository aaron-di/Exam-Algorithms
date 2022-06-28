#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1010;
vector<int> F[N];

vector<int> mul(vector<int>& A, int b) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

int main() {
    int n;
    F[0] = {1};
    for (int i = 1; i <= 1000; i++) F[i] = mul(F[i - 1], i);

    while (cin >> n) {
        for (int i = F[n].size() - 1; i >= 0; i--) {
            cout << F[n][i];
        }
        cout << endl;
    }

    return 0;
}