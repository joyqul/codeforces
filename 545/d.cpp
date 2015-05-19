#include <bits/stdc++.h>

using namespace std;

bool cmp(const int a, const int b) {
    return a < b;
}

long long input[100005];
/* take, take timestamp, not take, not take timestamp */
int n;

void solve() {
    int ans = 0;
    int ts = 0;
    for (int i = 0; i < n; ++i) {
        if (input[i] >= ts) {
            ts += input[i];
            ++ans;
        }
    }
    cout << ans << endl;
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    sort(input, input+n, cmp);
    solve();
    return 0;
}
