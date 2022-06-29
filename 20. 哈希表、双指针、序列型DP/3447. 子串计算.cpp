#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        map<string, int> hash;

        for (int i = 0; i < str.size(); i++) {
            string s;
            for (int j = i; j < str.size(); j++) {
                s += str[j];
                hash[s]++;
            }
        }

        for (auto it : hash) {
            if (it.second > 1) {
                cout << it.first << " " << it.second << endl;
            }
        }
    }

    return 0;
}