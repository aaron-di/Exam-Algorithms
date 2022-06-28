#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int add(vector<int>& A, vector<int>& B) {
    int res = 0;
    for (int i = 0, t = 0; i < A.size() || i < B.size() || t; i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        t /= 10;
        res += t;
    }

    return res;
}

int main() {
    string a, b;
    while (cin >> a >> b, a != "0" || b != "0")  {
        vector<int> A, B;
        for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
        for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
        int res = add(A, B);
        if (res == 0) puts("No carry operation.");
        else if (res == 1) puts("1 carry operation.");
        else printf("%d carry operations.\n", res);
    }

    return 0;
}