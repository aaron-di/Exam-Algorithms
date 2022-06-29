#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class CPoint {
   public:
    double x, y;

    CPoint() {}
    CPoint(double _x, double _y) : x(_x), y(_y) {}

    double operator-(const CPoint& t) const {
        double dx = x - t.x;
        double dy = y - t.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        CPoint x(a, b), y(c, d);
        printf("%.2lf\n", x - y);
    }

    return 0;
}