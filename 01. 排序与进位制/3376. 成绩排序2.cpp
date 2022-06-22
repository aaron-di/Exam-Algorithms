#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

struct Student {
    int id;
    int score;

    bool operator< (const Student& t) const {
        if (score != t.score) {
            return score < t.score;
        } else {
            return id < t.id;
        }
    }
} q[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i].id >> q[i].score;
    }

    sort(q, q + n);

    for (int i = 0; i < n; i++) {
        cout << q[i].id << " " << q[i].score << endl;
    }

    return 0;
}