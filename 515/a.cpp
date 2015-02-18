#include <bits/stdc++.h>

using namespace std;

int main () {
    int x, y, step;
    scanf("%d%d%d", &x, &y, &step);
    int dist = abs(x)+abs(y);
    if (step < dist) {
        cout << "No" << endl;
    }
    else {
        if ((step-dist)%2 == 0) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
