#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int n;
string start;

int bfs(string start) {
    queue<string> q;
    unordered_map<string, int> dist;
    q.push(start);
    dist[start] = 0;

    while (q.size()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (t.substr(i, 4) == "2012") {
                return dist[t];
            }
        }

        for (int i = 1; i < n; i++) {
            string r = t;
            swap(r[i], r[i - 1]);
            if (!dist.count(r)) {
                dist[r] = dist[t] + 1;
                q.push(r);
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> start;
    int res = bfs(start);
    cout << res << endl;

    return 0;
}