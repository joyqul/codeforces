#include <iostream>
#include <cstdio>
#define MAX_CITY 100005
#define INF 1000000010
#define MOD 1000000007

using namespace std;

int city_num, road_num;
int cost[MAX_CITY], head[MAX_CITY], dfs[MAX_CITY];
int top = -1, level = 0;
long long ans = 0, way = 1;
bool visit[MAX_CITY];

struct ROAD {
    int city;
    int next;
} road[300005];

void init() {
    top = -1, level = 0, ans = 0, way = 1;
    for (int i = 0; i < MAX_CITY; ++i) {
        head[i] = -1;
        dfs[i] = 0;
        visit[i] = false;
    }
}

void add(int th, int a, int b) {
    road[th].city = b;
    // record city a's road
    road[th].next = head[a];
    head[a] = th;
}

int mini(int a, int b) {
    return a < b? a: b;
}

int que[MAX_CITY], circle[MAX_CITY];
void tarjan(int node) {
    circle[node] = dfs[node] = ++level;
    que[++top] = node;
    visit[node] = true;
    for (int i = head[node]; i != -1; i = road[i].next) {
        int visit_city = road[i].city;
        if (!dfs[visit_city]) {
            tarjan(visit_city);
            circle[node] = mini(circle[node], circle[visit_city]);
        }
        else if (visit[visit_city]) {
            circle[node] = mini(circle[node], dfs[visit_city]);
        }
    }

    // if node is the key node
    int min_cost = INF, same_cost = 1;
    if (circle[node] == dfs[node]) {
        int tmp;
        do {
            tmp = que[top--];
            visit[tmp] = false;
            int pre = min_cost;
            min_cost = mini(min_cost, cost[tmp]);
            if (pre == cost[tmp]) ++same_cost;
            else if (pre != min_cost) same_cost = 1;
        } while (tmp != node);
        ans += min_cost;
        way = (way * same_cost) % MOD;
    }
}

int main () {
    while (scanf("%d", &city_num) != EOF) {
        init();
        for (int i = 0; i < city_num; ++i)
            scanf("%d", &cost[i]);
        scanf("%d", &road_num);
        for (int i = 0; i < road_num; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(i, a-1, b-1);
        }
        for (int i = 0; i < city_num; ++i) {
            if (!dfs[i])
                tarjan(i);
        }
        cout << ans << " " << way << endl;
    }
    return 0;
}
