#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

int n;
int q[N], w[N], s[N];

void bucket_sort()
{
    for (int i = 0; i < n; i ++ ) s[q[i]] ++ ;
    for (int i = 1; i < N; i ++ ) s[i] += s[i - 1];
    for (int i = n - 1; i >= 0; i -- ) w[ -- s[q[i]]] = q[i];
    for (int i = 0; i < n; i ++ ) q[i] = w[i];
}

void radix_sort(int d, int r)
{
    int radix = 1;
    for (int i = 1; i <= d; i ++ )
    {
        for (int j = 0; j < r; j ++ ) s[j] = 0;
        for (int j = 0; j < n; j ++ ) s[q[j] / radix % r] ++ ;
        for (int j = 1; j < r; j ++ ) s[j] += s[j - 1];
        for (int j = n - 1; j >= 0; j -- ) w[ -- s[q[j] / radix % r]] = q[j];
        for (int j = 0; j < n; j ++ ) q[j] = w[j];
        radix *= r;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    // bucket_sort();
    radix_sort(10, 10);

    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);

    return 0;
}