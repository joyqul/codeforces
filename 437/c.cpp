#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    int size[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &size[i]);
    long long int cost = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        cost += min(size[a-1], size[b-1]);
    }
    cout << cost << endl;
    return 0;
}
