#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size() || t; i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

int main() {
    string s;

    vector<int> res;
    while (cin >> s, s != "0") {
        vector<int> A;
        for (int i = s.size() - 1; i >= 0; i--) {
            A.push_back(s[i] - '0');
        }
        res = add(res, A);
    }

    while (res.size() > 1 && !res.back()) res.pop_back();
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << endl;

    return 0;
}