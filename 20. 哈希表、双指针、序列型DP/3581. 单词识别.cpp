#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    map<string, int> hash;
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            int j = i;
            string s;
            while (j < str.size() && isalpha(str[j])) {
                s += tolower(str[j]);
                j++;
            }
            hash[s]++;
            i = j - 1;
        }
    }
    for (auto it : hash) {
        printf("%s:%d\n", it.first.c_str(), it.second);
    }

    return 0;
}