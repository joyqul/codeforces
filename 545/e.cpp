#include <bits/stdc++.h>

using namespace std;

int parent[300005];
int n, m;

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    int pa = Find(a), pb = Find(b);
    parent[pa] = pb;
}

struct LINE {
    int x, y;
    long long cost, new_cost;
    int id;
    bool operator<(const LINE& rhs) const {
        if (new_cost > rhs.new_cost) return true;
        if (new_cost < rhs.new_cost) return false;
        if (cost > rhs.cost) return true;
        if (cost < rhs.cost) return false;
        return false;
    }
};

struct NODE {
    vector<LINE> neighber;
} node[300005];

bool cmp(const LINE& a, const LINE& b) {
    return a.cost < b.cost;
}

bool cmp2(const int a, const int b) {
    return a < b;
}

int main () {
    for (int i = 0; i < 300005; ++i) parent[i] = i;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        LINE tmp;
        scanf("%d%d", &x, &y);
        cin >> tmp.cost;
        --x, --y;
        tmp.x = x, tmp.y = y;
        tmp.id = i+1;
        node[x].neighber.push_back(tmp);
        node[y].neighber.push_back(tmp);
    }

    int st;
    scanf("%d", &st);
    --st;
    
    vector<int> ans;
    long long dist[300005];
    memset(dist, 0, sizeof(dist));
    priority_queue<LINE> record;
    for (int i = 0; i < node[st].neighber.size(); ++i) {
        node[st].neighber[i].new_cost = node[st].neighber[i].cost;
        record.push(node[st].neighber[i]);
    }

    long long weight = 0;
    while (record.size()) {
        LINE now = record.top();
        record.pop();
        int a = now.x, b = now.y;
        if (Find(a) == Find(b)) continue;
        if (Find(b) == Find(st)) {
            int tmp = b; b = a; a = tmp;
        }
        dist[b] = now.new_cost;
        Union(a, b);
        for (int i = 0; i < node[b].neighber.size(); ++i) {
            node[b].neighber[i].new_cost = dist[b]+node[b].neighber[i].cost;
            record.push(node[b].neighber[i]);
        }
        ans.push_back(now.id);
        weight += now.cost;
    }
    sort(ans.begin(), ans.end(), cmp2);
    cout << weight << endl;
    if (ans.size()) cout << ans[0];
    for (int i = 1; i < ans.size(); ++i) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}
