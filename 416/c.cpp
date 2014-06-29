#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct table {
    int id;
    int limit;
    bool empty;
} t[1005];

struct group {
    int id;
    int num;
    int money;
} g[1005];

struct answer {
    int g_id;
    int t_id;
} ans[1005];

bool cmp1(table ta, table tb) {
    return ta.limit < tb.limit;
}

bool cmp2(group ga, group gb) {
    if (ga.money != gb.money)
        return ga.money > gb.money;
    else 
        return ga.num < gb.num;
}

int tables;
int search(int size) {
    for (int i = 0; i < tables; ++i) {
        if (t[i].limit >= size && t[i].empty) {
            t[i].empty = false;
            return t[i].id;
        }
    }
    return -1;
}

int main () {
    int request;
    scanf("%d", &request);
    for (int i = 0; i < request; ++i) {
        scanf("%d%d", &(g[i].num), &(g[i].money));
        g[i].id = i + 1;
    }

    scanf("%d", &tables);
    for (int i = 0; i < tables; ++i) {
        scanf("%d", &t[i].limit);
        t[i].id = i + 1;
        t[i].empty = true;
    }

    sort(t, t+tables, cmp1);
    sort(g, g+request, cmp2);

    int accept_num = 0, gain_money = 0;
    for (int i = 0; i < request; ++i) {
        int pos = search(g[i].num);
        if (pos == -1) continue;
        ans[accept_num].t_id = pos;
        ans[accept_num].g_id = g[i].id;
        ++accept_num;
        gain_money += g[i].money;
    }

    cout << accept_num << " " << gain_money << endl;
    for (int i = 0; i < accept_num; ++i)
        cout << ans[i].g_id << " " << ans[i].t_id << endl;

    return 0;
}
