#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-8;

struct CPoint {
    double x, y;

    double operator- (const CPoint& t) const {
        double dx = x - t.x;
        double dy = y - t.y;
        return sqrt(dx * dx + dy * dy);
    }
};

struct CTriangle {
    CPoint a, b, c;

    bool check() {
        double d[3] = {a - b, a - c, b - c};
        sort(d, d + 3);
        if (fabs(d[0] * d[0] + d[1] * d[1] - d[2] * d[2]) < eps) return true;
        else return false;
    }

    double get_len() {
        return (a - b) + (b - c) + (a - c);
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        CTriangle t;
        cin >> t.a.x >> t.a.y >> t.b.x >> t.b.y >> t.c.x >> t.c.y;
        if (t.check()) {
            puts("Yes");
        } else {
            puts("No");
        }
        printf("%.2lf\n", t.get_len());
    }

    return 0;
}