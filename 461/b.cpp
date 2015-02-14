#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MODULE 1000000007
#define MAX 100005

using namespace std;
int n, st;
bool visit[MAX];
long long ans = 1;

struct NODE {
    vector<int> connect;
    int color;
} node[MAX];

struct DATA {
    bool branch;
    long long back;
};

DATA dfs(int pos, long long front, long long back, long long down, bool branch) {
    cout << "POS: " << pos << endl;
    DATA now;
    now.branch = branch;
    now.back = back;

    for (int i = 0; i < node[pos].connect.size(); ++i) {
        int target = node[pos].connect[i];
        cout << "TAR: " << target << endl;
        if (visit[target]) continue;
        visit[target] = true;

        if (node[target].color) {
            if (branch) {
                ans = ( ans*( ( ( (front*back) % MODULE)*down) %MODULE) ) % MODULE;
            }
            else {
                ans = (ans*(front+1)) % MODULE;
                now.branch = true;
                now.back = 0;
            }
            dfs(target, 0, 0, 0, false);
        }

        else {
            if (branch) {
                dfs(target, front, back, down+1, branch);
            }
            else {
                DATA tmp = dfs(target, front+1, back, down, branch);
                now.branch = tmp.branch;
                now.back = tmp.back + 1;
            }
        }
    }

    return now;
}

void dfs() {
    visit[st] = true;
    dfs(st, 0, 0, 0, false);
}

void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < node[i].connect.size(); ++j) 
            cout << node[i].connect[j] << " ";
        cout << endl;
    }
    for (int i = 0; i < n; ++i) 
        cout << node[i].color << endl;
}

int main () {
    scanf("%d", &n);
    memset(visit, false, sizeof(visit));
    for (int i = 1; i < n; ++i) {
        int target;
        scanf("%d", &target);
        node[target].connect.push_back(i);
        node[i].connect.push_back(target);
    }

    bool has_answer = false;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &node[i].color);
        if (node[i].color) {
            has_answer = true;
            st = i;
        }
    }

    //print();
    if (!has_answer) cout << 0 << endl;
    else {
        dfs();
        cout << ans << endl;
    }
    return 0;
}
