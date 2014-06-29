#include <iostream>
#include <cstdio>
#define MOD 1000000007
#define MAX 101

using namespace std;
int dp_has[MAX], dp_no[MAX];
int k, d;

void ways(int n) {
    if (dp_has[n] != -1 && dp_no[n] != -1) return;
    int tmp_has = 0, tmp_no = 0;
    for (int i = 1; i <= k && i <= n; ++i) {
        bool has_d = i >= d? true: false;
        ways(n - i);
        if (has_d) {
            tmp_has = ((tmp_has + dp_no[n - i]) % MOD + dp_has[n - i]) % MOD;
        }
        else {
            tmp_has = (tmp_has + dp_has[n - i]) % MOD;
            tmp_no = (tmp_no + dp_no[n - i]) % MOD;
        }
    }
    dp_has[n] = tmp_has;
    dp_no[n] = tmp_no;
}

void init() {
    for (int i = 0; i < MAX; ++i) {
        dp_has[i] = -1;
        dp_no[i] = -1;
    }
    dp_no[0] = 1;
    dp_has[0] = 0;
}

int main () {
    int n;
    scanf("%d%d%d", &n, &k, &d);
    init();
    ways(n);
    printf("%d\n", dp_has[n]);
    return 0;
}
