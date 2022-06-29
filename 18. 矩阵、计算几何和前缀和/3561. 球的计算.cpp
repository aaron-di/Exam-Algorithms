#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

const double PI = acos(-1);

int main() {
    int T;
    cin >> T;
    while (T--) {
        double x0, y0, z0, x1, y1, z1;
        cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;

        double dx = x0 - x1;
        double dy = y0 - y1;
        double dz = z0 - z1;

        double r = sqrt(dx * dx + dy * dy + dz * dz);
        double v = 4.0 / 3 * PI * r * r * r;

        printf("%.2lf %.2lf\n", r, v);
    }

    return 0;
}