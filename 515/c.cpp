#include <bits/stdc++.h>

using namespace std;

int prime[] = { 2, 3, 5, 7 };
int num[10];

void add(int target) {
    for (int i = 2; i <= target; ++i) {
        int tmp = i;
        for (int j = 0; j < 4; ++j) {
            while (tmp%prime[j] == 0) {
                ++num[prime[j]];
                tmp /= prime[j];
            }
        }
    }
}

void solve() {
    if (num[7] != 0) {
        for (int i = 0; i < num[7]; ++i) {
            cout << 7;
        }
        num[2] -= 4*num[7];
        num[3] -= 2*num[7];
        num[5] -= num[7];
        num[7] = 0;
    }

    if (num[5] != 0) {
        for (int i = 0; i < num[5]; ++i) {
            cout << 5;
        }
        num[2] -= 3*num[5];
        num[3] -= num[5];
        num[5] = 0;
    }

    if (num[3] != 0) {
        for (int i = 0; i < num[3]; ++i) {
            cout << 3;
        }
        num[2] -= num[3];
        num[3] = 0;
    }

    for (int i = 0; i < num[2]; ++i) {
        cout << 2;
    }
    cout << endl;
}

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 10; ++i) num[i] = 0;
    getchar();
    for (int i = 0; i < n; ++i) {
        char ch;
        scanf("%c", &ch);
        add(ch-'0');
    }
    solve();
    
    return 0;
}
