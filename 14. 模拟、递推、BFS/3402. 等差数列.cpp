#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * 2;

int n, m;
int row[N], col[N];
int q[M], hh, tt = -1;
bool st[M];
PII ans[N * N];
int top;
int g[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            scanf("%d", &g[i][j]);
            if (g[i][j])
            {
                row[i] ++ ;
                col[j] ++ ;
            }
        }

    for (int i = 0; i < n; i ++ )
        if (row[i] >= 2 && row[i] < m)
        {
            q[ ++ tt] = i;
            st[i] = true;
        }
    for (int i = 0; i < m; i ++ )
        if (col[i] >= 2 && col[i] < n)
        {
            q[ ++ tt] = i + n;
            st[i + n] = true;
        }

    while (hh <= tt)
    {
        auto t = q[hh ++ ];
        if (t < n)  // 行
        {
            PII p[2];
            int cnt = 0;
            for (int i = 0; i < m; i ++ )
                if (g[t][i])
                {
                    p[cnt ++ ] = {i, g[t][i]};
                    if (cnt == 2) break;
                }
            int d = (p[1].y - p[0].y) / (p[1].x - p[0].x);
            int a = p[1].y - d * p[1].x;

            for (int i = 0; i < m; i ++ )
                if (!g[t][i])
                {
                    g[t][i] = a + d * i;
                    ans[top ++ ] = {t, i};
                    col[i] ++ ;
                    if (col[i] >= 2 && col[i] < m && !st[i + n])
                    {
                        q[ ++ tt] = i + n;
                        st[i + n] = true;
                    }
                }
        }
        else  // 列
        {
            t -= n;
            PII p[2];
            int cnt = 0;
            for (int i = 0; i < n; i ++ )
                if (g[i][t])
                {
                    p[cnt ++ ] = {i, g[i][t]};
                    if (cnt == 2) break;
                }
            int d = (p[1].y - p[0].y) / (p[1].x - p[0].x);
            int a = p[1].y - d * p[1].x;
            for (int i = 0; i < n; i ++ )
                if (!g[i][t])
                {
                    g[i][t] = a + d * i;
                    ans[top ++ ] = {i, t};
                    row[i] ++ ;
                    if (row[i] >= 2 && row[i] < n && !st[i])
                    {
                        q[ ++ tt] = i;
                        st[i] = true;
                    }
                }
        }
    }

    sort(ans, ans + top);
    for (int i = 0; i < top; i ++ )
    {
        auto& p = ans[i];
        printf("%d %d %d\n", p.x + 1, p.y + 1, g[p.x][p.y]);
    }

    return 0;
}