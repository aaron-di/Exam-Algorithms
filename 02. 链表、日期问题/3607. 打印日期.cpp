#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int year, x;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    while (cin >> year >> x) {
        if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
            days[2] = 29;
        } else {
            days[2] = 28;
        }

        int month = 1, day = 0;
        while (x--) {
            day++;
            if (day > days[month]) {
                day = 1;
                month++;
            }
        }

        printf("%04d-%02d-%02d\n", year, month, day);
    }

    return 0;
}