#include <iostream>
#include <cstdio>
#define MAX 100005

using namespace std;

long long sum[MAX], dp[2][MAX];
bool chosed[2][MAX];
int n;

long long max(long long x, long long y) {
    return x > y? x: y;
}

void do_dp() {
    dp[0][0] = 0;
    dp[1][0] = sum[0];
    for (long long i = 1; i < MAX; ++i) {
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
        dp[1][i] = dp[0][i-1] + sum[i];
    }
}

void init() {
    for (long long i = 0; i < MAX; ++i) {
        sum[i] = 0;
        for (long long j = 0; j < 2; ++j) {
            dp[j][i] = 0;
            chosed[j][i] = false;
        }
    }
}

int main () {
    while (scanf("%d", &n) != EOF) {
        init();
        for (int i = 0; i < n; ++i) {
            int num;
            scanf("%d", &num);
            sum[num] += num;
        }
        do_dp();
        cout << max(dp[0][MAX-1], dp[1][MAX-1]) << endl;
    }
    return 0;
}
