#include <bits/stdc++.h>

using namespace std;

bool happy_boy[110], happy_girl[110];
int b, g;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

int lcm(int x, int y) {
    int gcd_ab = gcd(max(x,y), min(x,y));
    return x*y/gcd_ab;
}

int main () {

    memset(happy_boy, false, sizeof(happy_boy));
    memset(happy_girl, false, sizeof(happy_girl));
    scanf("%d%d", &b, &g);

    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        happy_boy[tmp] = true;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int tmp;
        scanf("%d", &tmp);
        happy_girl[tmp] = true;
    }

    if (b == g && b == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    while (1) {
        bool change = false;
        for (int i = 0; i < lcm(b, g); ++i) {
            int target_b = i%b, target_g = i%g;
            if (happy_boy[target_b] && happy_girl[target_g]) continue;
            if (!happy_boy[target_b] && !happy_girl[target_g]) continue;
            happy_boy[target_b] = true;
            happy_girl[target_g] = true;
            change = true;
        }
        if (!change) break;
    }

    for (int i = 0; i < b; ++i) {
        if (!happy_boy[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 0; i < g; ++i) {
        if (!happy_girl[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
