#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

struct Person {
    string name;
    int score;
    
    bool operator< (const Person& t) const {
        return score < t.score;
    }
    
    bool operator> (const Person& t) const {
        return score > t.score;
    }
}person[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> person[i].name >> person[i].score;
    }
    
    if (m == 0) {
        stable_sort(person, person + n, greater<int>());
    } else {
        stable_sort(person, person + n);
    }
    
    return 0;
}