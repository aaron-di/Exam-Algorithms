#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

const int N = 10010;

int n;
string logs[N];

bool mycmp(string a, string b) {
    stringstream ssina(a), ssinb(b);
    string sa[4], sb[4];
    for (int i = 0; i < 4; i++) {
        ssina >> sa[i];
        ssinb >> sb[i];
    }
    if (sa[3] == sb[3]) return sa[1] + sa[2] < sb[1] + sb[2];

    double ta, tb;
    sscanf(sa[3].c_str(), "%lf(s)", &ta);
    sscanf(sb[3].c_str(), "%lf(s)", &tb);
    return ta < tb;
}

int main() {
    while (getline(cin, logs[n])) {
        if (logs[n].size() > 0) n++;
        else break;
    }

    sort(logs, logs + n, mycmp);

    for (int i = 0; i < n; i++) {
        cout << logs[i] << endl;
    }

    return 0;
}