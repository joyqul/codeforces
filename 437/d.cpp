#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 100000

using namespace std;

struct ROAD {
    int from, to;
    int cost;
} road[MAX];

int cost[MAX], parent[MAX], num[MAX];
int n, m;

void init() {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        num[i] = 1;
    }
}

bool func(struct ROAD x, struct ROAD y) {
    return x.cost > y.cost;
}

int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
        return parent[x];
    }
    return x;
}

void disunion(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);
    
    parent[x_parent] = y_parent;
    num[y] += num[x];
    num[x] = 0;
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &cost[i]);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        road[i].from = a - 1;
        road[i].to = b - 1;
        road[i].cost = min(cost[a - 1], cost[b - 1]);
    }
    sort(road, road + m, func);
    init();
    double ans = 0.0;
    for (int i = 0; i < m; ++i) {
        int x = find(road[i].from), y = find(road[i].to);
        if (x == y) continue;
        else {
            ans += (road[i].cost * 1.0 * num[x] * num[y]);
            disunion(x, y);
        }
    }

    double total = n * 0.5 * (n-1);
    printf("%.6lf\n", ans * 1.0 / total);
    return 0;
}
