#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int n, t, c;
    bool prisoner[200005];
    while (scanf("%d%d%d", &n, &t, &c) != EOF) {
        for (int i = 0; i < n; ++i) {
            int primes;
            scanf("%d", &primes);
            if (primes <= t) prisoner[i] = true;
            else prisoner[i] = false;
        }
        int ways = 0, cons = 0;
        for (int i = 0; i < n; ++i) {
            if (prisoner[i]) ++cons;
            else cons = 0;
            if (cons >= c) ++ways;
        }
        printf("%d\n", ways);
    }
    return 0;
}
