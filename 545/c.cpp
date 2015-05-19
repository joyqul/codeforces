#include <bits/stdc++.h>

using namespace std;

/* x, h, lay left num, lay right num, dont't lay */
int points[100005][5];
int n;

void solve() {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    points[0][2] = 1;
    if (points[0][0]+points[0][1] < points[1][0]) points[0][3] = 1;
    points[0][4] = 1;

    for (int i = 1; i < n-1; ++i) {
        /* lay left */
        int h = points[i][1];
        if (points[i][0]-h > points[i-1][0]) {
            points[i][2] = max(points[i-1][2]+1, points[i-1][4]+1);
        }
        if (points[i][0]-h > points[i-1][0]+h) {
            points[i][2] = max(points[i][2], points[i-1][3]+1);
        }
        points[i][4] = max( max(points[i-1][2], points[i-1][3]), points[i-1][4]);
        if (points[i][0]+h < points[i+1][0]) {
            points[i][3] = points[i][4]+1;
        }
    }
    cout << max(points[n-2][2], max(points[n-2][3], points[n-2][4]))+1 << endl;
}

int main () {
    scanf("%d", &n);
    memset(points, 0, sizeof(points));
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &points[i][0], &points[i][1]);
    }
    solve();
    return 0;
}
