#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int testcase;
    scanf("%d", &testcase);
    while (testcase--) {
        int n, p;
        scanf("%d%d", &n, &p);
        int max = 2*n + p;
        for (int j = 0; j < max; ++j) {
            for (int i = 1; i < n; ++i) {
                for (int k = i+1; k <= n ;++k) {
                    cout << i << " " << k << endl;
                    ++j;
                    if (j >= max) break;
                }
                if (j >= max) break;
            }
        }
    }
    return 0;
}
