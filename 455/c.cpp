#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 300005

using namespace std;

int n, m, k;
int parent[MAX], length[MAX], sub_len[MAX], child[MAX];
bool leaf[MAX];

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void dis_union(int x, int y) {
    int root_x = find(x), root_y = find(y);
    if (root_x == root_y) return;
    length[root_y] = max( max(length[root_x], length[root_y]), (length[root_y]+1)/2 + (length[root_x]+1)/2 + 1 );
    parent[root_x] = root_y;
}

void reverse(int y) {
    if (y == parent[y]) {
        --child[y];
        if (child[y] == 0) leaf[y] = true;
        return;
    }
    int tmp = parent[y];
    reverse(parent[y]);
    parent[tmp] = y;
}

void normal_union(int x, int y) {
    if (parent[x] != x) {
        if (parent[y] != y) {
            ++child[y];
            reverse(y);
        }
        parent[y] = x;
        ++child[x];
        leaf[x] = false;
    }
    else {
        parent[x] = y;
        ++child[y];
        leaf[y] = false;
    }
}

void trace() {

    for (int i = 1; i < MAX; ++i) {
        int now = i;
        if (!leaf[i]) continue;
        while (now != parent[now]) {
            if (now != child[parent[now]]) sub_len[parent[now]] = max(sub_len[now], length[parent[now]] + length[now] + 1);
            else sub_len[parent[now]] = max(sub_len[parent[now]], sub_len[now]);
            if (length[now]+1 > length[parent[now]]) {
                child[parent[now]] = now;
                length[parent[now]] = length[now] + 1;
            }
            now = parent[now];
        }
    }

    for (int i = 1; i < MAX; ++i) {
        if (parent[i] != i) continue;
        length[i] = max(length[i], sub_len[i]);
    }

}

void init() {
    for (int i = 1; i < MAX; ++i) {
        parent[i] = i;
    }
    memset(length, 0, sizeof(length));
    memset(sub_len, 0, sizeof(sub_len));
    memset(leaf, true, sizeof(leaf));
    memset(child, 0, sizeof(child));
}

void print() {
    for (int i = 1; i <= n; ++i)
        cout << length[i] << " ";
    cout << endl;
}

int main () {
    while (scanf("%d%d%d", &n, &m, &k) != EOF) {
        init();
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            normal_union(a, b);
        }
        trace();
        //print();
        for (int i = 0; i < k; ++i) {
            int instr, a, b;
            scanf("%d%d", &instr, &a);
            if (instr == 1) {
                cout << length[find(a)] << endl;
            }
            else {
                scanf("%d", &b);
                dis_union(a, b);
            }
        }
    }
    return 0;
}
