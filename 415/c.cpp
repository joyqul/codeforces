#include <iostream>
#define MAX 10000003

using namespace std;

long long ans[MAX];

int main () {
    long long n, k;
    cin >> n >> k;
    int last = k - n/2 + 1;

    if (n == 1) {
        if (k == 0) cout << 1 << endl;
        else cout << -1 << endl;
    }
    else {
        if (n/2 > k) cout << -1 << endl;
        else {
            int index = 0;
            ans[index++] = last;
            ans[index++] = last * 2;
            for (int i = 0, j = n - 2; i < j; ++i)
                ans[index++] = last * 2 + 1 + i;

            for (int i = 0; i < n; ++i)
                cout << ans[i] << " ";
        }
    }

    return 0;
}
