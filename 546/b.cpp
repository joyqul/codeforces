#include <bits/stdc++.h>

using namespace std;

int input[3005];
int n;

bool cmp(const int& a, const int& b) {
    return a<b;
}

void solve() {
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (input[i] <= input[i-1]) {
            ans += (input[i-1]-input[i]+1);
            input[i] = input[i-1]+1;
        }
    }
    cout << ans << endl;
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &input[i]);
    }
    sort(input, input+n, cmp);
    solve();
    return 0;
}
