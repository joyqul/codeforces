#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 100010

using namespace std;

int tree[MAX][26];
bool win[MAX], lose[MAX];
int string_num, k_times;

void init() {
    memset(win, false, sizeof(win));
    memset(lose, false, sizeof(lose));
    memset(tree, 0, sizeof(tree));
}

int main () {
    while ( scanf("%d%d", &string_num, &k_times) != EOF ) {
        init();
        string str;
        int node_no = 0;
        while (string_num--) {
            cin >> str;

            int parent = 0;
            for (int i = 0; i < str.size(); ++i) {
                int ch = str[i] - 'a';
                if (tree[parent][ch]) parent = tree[parent][ch];
                else {
                    tree[parent][ch] = ++node_no;
                    parent = tree[parent][ch];
                }
            }
        }

        for (int child = node_no; child >= 0; --child) {
            bool is_leaf = true;
            for (int i = 0; i < 26; ++i) {
                if (tree[child][i]) {
                    is_leaf = false;
                    if (!win[tree[child][i]]) win[child] = true;
                    if (!lose[tree[child][i]]) lose[child] = true;
                }
            }
            if (is_leaf) {
                win[child] = false;
                lose[child] = true;
            }
        }

        if (win[0]) {
            if (lose[0]) cout << "First" << endl;
            else {
                if (k_times%2 == 1) cout << "First" << endl;
                else cout << "Second" << endl;
            }
        }
        else {
            cout << "Second" << endl;
        }
    }
    return 0;
}
