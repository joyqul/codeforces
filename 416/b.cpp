#include <iostream>
#include <cstdio>

using namespace std;

int paints[50001][6];
int ans[50001];

void init() {
    for (int i = 0; i < 50001; ++i)
        ans[i] = 0;
}

int main () {
    int pictures, painters;
    while (scanf("%d%d", &pictures, &painters) != EOF) {
        for (int i = 0; i < pictures; ++i) {
            for (int j = 0; j < painters; ++j)
                scanf("%d", &paints[i][j]);
        }
        init();
        ans[0] = paints[0][0];
        for (int i = 1; i < pictures; ++i)
            ans[i] = ans[i-1] + paints[i][0];

        for (int i = 1; i < painters; ++i) {
            ans[0] += paints[0][i];
            for (int j = 1; j < pictures; ++j) {
                ans[j] = max(ans[j - 1], ans[j]) + paints[j][i];
            }
        }

        cout << ans[0];
        for (int i = 1; i < pictures; ++i)
            cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}
