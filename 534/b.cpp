#include <bits/stdc++.h>
using namespace std;

bool legal(int top, int end, int last_t, int d) {
    if (top >= end) {
        return (top-last_t*d) <= end;
    }
    return true;
}

void find(int start, int end, int t, int d) {
    int ans = start;
    for (int i = 1; i < t-1; ++i) {
        int now = start+d*i;
        if (legal(now, end, t-i-1, d)) ans += now;
        else {
            ans += (end+end+d*(t-i-1))*(t-i)/2;
            ans -= end;
            break;
        }
    }
    ans += end;
    cout << ans << endl;
}

int main () {
    int v1, v2, t, d;
    scanf("%d%d%d%d", &v1, &v2, &t, &d);
    //solve(v1, v2, t, d);
    find(min(v1, v2), max(v1, v2), t, d);
    return 0;
}
