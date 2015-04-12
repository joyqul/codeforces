#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int stick[9];

int main () {
    int times = 6;
    for (int i = 0; i < 9; ++i)
        stick[i] = 0;
    while (times--) {
        int tmp;
        scanf("%d", &tmp);
        stick[tmp-1]++;
    }
    bool has_four = false, has_two = false;
    for (int i = 0; i < 9; ++i) {
        if (stick[i] == 2) has_two = true;
        if (stick[i] >= 4) has_four = true;
        if (stick[i] == 6) has_two = true;
    }
    if (has_two && has_four)
        cout << "Elephant" << endl;
    else if (has_four)
        cout << "Bear" << endl;
    else 
        cout << "Alien" << endl;
    return 0;
}
