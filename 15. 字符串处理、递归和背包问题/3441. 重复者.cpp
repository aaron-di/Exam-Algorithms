#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<string> p;

vector<string> g(int k)
{
    if (k == 1) return p;
    auto s = g(k - 1);
    int m = s.size();

    vector<string> res(n * m);
    for (int i = 0; i < n * m; i ++ )
        res[i] = string(n * m, ' ');

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (p[i][j] != ' ')
                for (int x = 0; x < m; x ++ )
                    for (int y = 0; y < m; y ++ )
                        res[i * m + x][j * m + y] = s[x][y];

    return res;
}

int main()
{
    while (cin >> n, n)
    {
        p.clear();
        getchar();  // 读掉n后的回车
        for (int i = 0; i < n; i ++ )
        {
            string line;
            getline(cin, line);
            p.push_back(line);
        }

        int k;
        cin >> k;
        auto res = g(k);
        for (auto& s: res) cout << s << endl;
    }

    return 0;
}