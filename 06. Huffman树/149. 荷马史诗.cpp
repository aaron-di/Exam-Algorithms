#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PLI;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    priority_queue<PLI, vector<PLI>, greater<PLI> > heap;
    while (n--) {
        LL w;
        scanf("%lld", &w);
        heap.push({w, 0});
    }
    while ((heap.size() - 1) % (k - 1)) heap.push({0, 0});

    LL res = 0;
    while (heap.size() > 1) {
        LL s = 0;
        int depth = 0;
        for (int i = 0; i < k; i++) {
            auto t = heap.top();
            heap.pop();
            s += t.first;
            depth = max(depth, t.second);
        }
        heap.push({s, depth + 1});
        res += s;
    }

    printf("%lld\n%d\n", res, heap.top().second);

    return 0;
}