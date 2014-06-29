#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int num_of_zero, num_of_one;
    scanf("%d%d", &num_of_zero, &num_of_one);
    if (num_of_one < num_of_zero - 1)
        cout << -1 << endl;
    else if (num_of_one > (num_of_zero + 1)*2)
        cout << -1 << endl;
    else {
        int cons_1 = 0;
        for (int i = 0, j = num_of_zero + num_of_one; i < j; ++i) {
            if (num_of_zero > num_of_one) {
                cout << 0;
                --num_of_zero;
                cons_1 = 0;
            }
            else if (cons_1 >=2 && num_of_zero) {
                cout << 0;
                --num_of_zero;
                cons_1 = 0;
            }
            else {
                cout << 1;
                --num_of_one;
                ++cons_1;
            }
        }
        cout << endl;
    }

    return 0;
}
