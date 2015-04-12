#include <bits/stdc++.h>
const long long MOD = 1e9+7;

using namespace std;

int n, x;
long long matrix[101][101];
long long a[100], f[101];

void multiply(long long matrix[][101], long long rhs[][101]) {
    long long result[101][101];
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            for (int k = 0; k < 101; ++k) {
                result[i][j] = (result[i][j] + matrix[i][k]*rhs[k][j])%MOD;
            }
        }
    }
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            matrix[i][j] = result[i][j];
        }
    }
}

void power(int times, long long result[][101]) {
    long long base[101][101];
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            result[i][j] = 0;
            base[i][j] = matrix[i][j];
        }
        result[i][i] = 1;
    }

    while (times > 0) {
        if ((times&1)) multiply(result, base);
        times >>= 1;
        multiply(base, base);
    }
}

void solve() {
    if (x == 0) {
        cout << 1 << endl;
        return;
    }
    memset(matrix, 0, sizeof(matrix));
    for (int i = 0; i < 99; ++i) matrix[i][i+1] = 1;
    for (int i = 0; i < 100; ++i) matrix[99][i] = a[99-i];
    matrix[100][99] = matrix[100][100] = 1;
    memset(f, 0, sizeof(f));
    f[0] = f[100] = a[0];
    ++f[100];
    if (x == 1) {
        cout << f[100] << endl;
        return;
    }

    /* build matrix */
    for (int i = 1; i < 100; ++i) {
        for (int j = 0; j < i; ++j) {
            f[i] = (f[i]+f[j]*a[i-j-1])%MOD;
        }
        f[i] = (f[i]+a[i])%MOD;
        if (i != 99) {
            f[100] = (f[100]+f[i])%MOD;
            if (x == i+1) {
                cout << f[100] << endl;
                return;
            }
        }
    }

    long long result[101][101];
    power(x-99, result);
    long long ans = 0;
    for (int j = 0; j < 101; ++j) {
        ans = (ans + result[100][j]*f[j])%MOD;
    }
    cout << ans << endl;
}

int main () {
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        int target;
        scanf("%d", &target);
        ++a[target-1];
    }
    solve();
    return 0;
}
