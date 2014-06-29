#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int box_section, nuts, divisors, capacity;
    scanf("%d%d%d%d", &box_section, &nuts, &divisors, &capacity);
    int box = 0;
    while (nuts > 0) {
        if (divisors) {
            if (divisors+1 >= box_section) {
                nuts -= box_section * capacity;
                ++box;
                divisors = divisors - box_section + 1;
            }
            else {
                nuts -= (divisors + 1) * capacity;
                ++box;
                divisors = 0;
            }
        }
        else {
            nuts -= capacity;
            ++box;
        }
    }
    cout << box << endl;
    return 0;
}
