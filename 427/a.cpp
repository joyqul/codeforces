#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int n;
    while (scanf("%d", &n) != EOF) {
        int max = 0, police = 0;
        while (n--) {
            int tmp;
            scanf("%d", &tmp);
            police += tmp;
            if (police < max) max = police;
        }
        printf("%d\n", -max);
    }
    return 0;
}
