#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <unordered_map>

using namespace std;

struct AC_Automaton {
    static const int MAX_N = 1e6+10;
    static const int MAX_CHILD = 3;

    int n;
    int fail[MAX_N];
    int tag[MAX_N];
    int trie[MAX_N][MAX_CHILD];

    void clean(int target) {
        for (int i = 0; i < MAX_CHILD; ++i) {
            trie[target][i] = -1;
        }
    }

    void reset () {
        clean(0);
        n = 1;
        memset(tag, 0, sizeof(tag));
    }

    void add(char* s) {
        int p = 0;
        while (*s) {
            int id = get_id(s[0]);
            if (trie[p][id] == -1) {
                clean(n);
                trie[p][id] = n++;
            }
            p = trie[p][id];
            ++s;
        }
        ++tag[p];
    }

    void construct() {
        queue<int> que;
        fail[0] = 0;

        for (int i = 0; i < MAX_CHILD; ++i) {
            if (trie[0][i] != -1) {
                fail[trie[0][i]] = 0;
                que.push(trie[0][i]);
            }
            else {
                trie[0][i] = 0;
            }
        }

        while (que.size()) {
            int now = que.front();
            que.pop();

            for (int i = 0; i < MAX_CHILD; ++i) {
                int target = trie[now][i];
                if (target != -1) {
                    que.push(target);
                    fail[target] = trie[fail[now]][i];
                }
                else {
                    trie[now][i] = trie[fail[now]][i];
                }
            }
        }
    }

    bool dfs(int x, bool changed, char* s, int len, int now) {
        //cout << now << " in " << len << endl;
        if (now == len) {
            if (!changed) return false;
            return tag[x];
        }

        int next = get_id(s[now]);
        if (trie[x][next] > 0 && dfs(trie[x][next], changed, s, len, now+1)) return true;

        if (!changed) {
            for (int i = 0; i < 3; ++i) {
                if (i == next) continue;
                if (trie[x][i] < 0) continue;
                if (dfs(trie[x][i], true, s, len, now+1)) return true;
            }
        }
        return false;
    }

    int solve(char* s) {
        return dfs(0, false, s, strlen(s), 0);
    }

    int get_id(const char& ch) {
        if (ch <= 'z' && ch >= 'a') return ch-'a';
        else return ch-'A'+26;
    }
} ac;

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    ac.reset();
    char input[600010];
    for (int i = 0; i < n; ++i) {
        scanf("%s", input);
        ac.add(input);
    }

    for (int i = 0; i < m; ++i) {
        scanf("%s", input);
        if (ac.solve(input) > 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
