#include <iostream>
#include <cstdio>

using namespace std;
int cost[4];
string str;

int main () {
    while (scanf("%d%d%d%d", &cost[0], &cost[1], &cost[2], &cost[3]) != EOF) {
        cin >> str;
        int ans = 0;
        for (int i = 0, j = str.size(); i < j; ++i) {
            if (str[i] == '1') ans += cost[0];
            else if (str[i] == '2') ans += cost[1];
            else if (str[i] == '3') ans += cost[2];
            else ans += cost[3];
        }
        printf("%d\n", ans);
    }
    return 0;
}
