#include <iostream>
#include <cstdio>

using namespace std;

int mini(int a, int b) {
    if (b == -1) return a;
    else return a < b? a: b;
}

int main () {
    int n, k;
    int h[1000];
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &h[i]);
    
    int modify = 0, plus = 0, change = -1;
    for (int first = 1; first <= 1000; ++first) {
        int now = first;
        for (int i = 0; i < n; ++i) {
            if (now != h[i]) ++modify;
            now += k;
        }
        if (mini(modify, change) == modify) {
            change = modify;
            plus = first;
        }
        modify = 0;
    }
    
    cout << change << endl;

    int now = plus;
    for (int i = 0; i < n; ++i) {
        if (now > h[i]) {
            cout << "+ " << i+1 << " " << now - h[i] << endl;
        }
        else if (now < h[i]) {
            cout << "- " << i+1 << " " << h[i] - now << endl;
        }
        now += k;
    }
    
    return 0;
}
