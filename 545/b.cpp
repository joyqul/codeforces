#include <bits/stdc++.h>

using namespace std;

char input[2][100005];

int main () {
    scanf("%s%s", input[0], input[1]);
    int value[2];
    value[0] = value[1] = 0;
    int mysize = 0;
    for (int i = 0; i < 2; ++i) {
        int j = 0;
        char tmp = input[i][j];
        while (tmp == '0' || tmp == '1') {
            if (tmp == '1') ++value[i];
            ++j;
            tmp = input[i][j];
            ++mysize;
        }
    }
 
    mysize /= 2;
    int diff = value[0]-value[1];
    if (diff%2 != 0) {
        cout << "impossible" << endl;
    }
    else {
        diff /= 2;
        if (diff == 0) {
            for (int i = 0; i < mysize; ++i) {
                cout << 0;
            }
        }
        else if (diff < 0) {
            for (int i = 0; i < mysize; ++i) {
                if (diff != 0 && input[0][i] == '0' && input[1][i] == '1') {
                    ++diff;
                    cout << 1;
                }
                else {
                    cout << 0;
                }
            }
        }
        else {
            for (int i = 0; i < mysize; ++i) {
                if (diff != 0 && input[1][i] == '0' && input[0][i] == '1') {
                    --diff;
                    cout << 1;
                }
                else {
                    cout << 0;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
