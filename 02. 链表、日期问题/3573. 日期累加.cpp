#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int T;
int year, month, day;
int x;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap(int year) {
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
        return 1;
    } else {
        return 0;
    }
}
int get_days_by_year(int year, int month) {
    if (month <= 2)
        return 365 + is_leap(year);
    else
        return 365 + is_leap(year + 1);
}

int main() {
    cin >> T;
    while (T--) {
        cin >> year >> month >> day >> x;

        if (month == 2 && day == 29)
            month = 3, day = 1, x--;

        while (x > get_days_by_year(year, month)) {
            x -= get_days_by_year(year, month);
            year++;
        }

        if (is_leap(year)) {
            days[2] = 29;
        } else {
            days[2] = 28;
        }

        while (x--) {
            day++;
            if (day > days[month]) {
                month++;
                day = 1;
                if (month > 12) {
                    year++;
                    if (is_leap(year)) {
                        days[2] = 29;
                    } else {
                        days[2] = 28;
                    }
                    month = 1;
                }
            }
        }

        printf("%04d-%02d-%02d\n", year, month, day);
    }

    return 0;
}