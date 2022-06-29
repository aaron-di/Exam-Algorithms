#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

double n, k;

int main() {
    while (cin >> n >> k) {
        double saving = n;
        double house = 200;

        int res = 0;
        while (true) {
            res++;
            if (res > 21) {
                cout << "Impossible" << endl;
                break;
            }

            if (saving >= house) {
                cout << res << endl;
                break;
            }
            saving += n;
            house = house * (1 + k / 100);
        }
    }

    return 0;
}