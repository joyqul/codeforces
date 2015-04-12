#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9+7;
const int MAX = 1e5+1;

int num[4];

long long power(int base, int N) {
    long long ans = 1;
    long long now = base;
    while (N) {
        if (N&1) { ans = ans*now%MOD; }
        now = now*now%MOD;
        N >>= 1;
    }
    return ans;
}

int main () {
    int len;
    char input[MAX];
    scanf("%d%s", &len, input);
    memset(num, 0, sizeof(num));

    for (int i = 0; i < len; ++i) {
        if (input[i] == 'A') num[0]++;
        if (input[i] == 'C') num[1]++;
        if (input[i] == 'G') num[2]++;
        if (input[i] == 'T') num[3]++;
    }

    int base = 1, N = 0;
    for (int i = 0; i < 4; ++i) {
        if (num[i] > N) {
            base = 1;
            N = num[i];
        }
        else if (num[i] == N) ++base;
    }

    cout << power(base, len) << endl;
    return 0;
}
