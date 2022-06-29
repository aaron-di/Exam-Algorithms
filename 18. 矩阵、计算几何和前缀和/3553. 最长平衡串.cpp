#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1000010;

int n;
char str[N];

int main() {
    scanf("%s", str + 1);
    unordered_map<int, int> hash;
    n = strlen(str + 1);

    hash[0] = 0;
    int res = 0;
    for (int i = 1, s = 0; i <= n; i++) {
        if (str[i] == '0') s++;
        else s--;

        if (hash.count(s)) res = max(res, i - hash[s]);
        else hash[s] = i;
    }

    printf("%d\n", res);

    return 0;
}