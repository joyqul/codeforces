#include <bits/stdc++.h>

using namespace std;

enum {TOP, RIGHT, DOWN, LEFT};

struct POS {
    int x, y, way;
    POS() {}
    POS(int x, int y):x(x), y(y) {}
};

int n, m;
char mymap[2010][2010];
char trans[4][2] = { {'v', '^'}, {'<', '>'}, {'^', 'v'}, {'>', '<'}};
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool in_map(int x, int y) {
    return !(x<0 || x>n || y<0 || y>m);
}

bool legal(int x, int y, int dir_x, int dir_y) {
    if (!in_map(x+dir_x, y+dir_y)) return false;
    return mymap[x+dir_x][y+dir_y] == '.';
}

queue<POS> path;

void check(int x, int y) {
    if (!in_map(x, y) || mymap[x][y] != '.') return;
    POS now(x, y);
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        if (legal(x, y, dir[i][0], dir[i][1])) {
            ++ans;
            now.way = i;
        }
    }
    if (ans == 1) path.push(now);
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", mymap[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            check(i, j);
        }
    }
    
    while (path.size()) {
        POS now = path.front();
        path.pop();
        int target_x = now.x+dir[now.way][0], target_y = now.y+dir[now.way][1];
        if (mymap[now.x][now.y] == '.' && mymap[target_x][target_y] == '.') {
            mymap[now.x][now.y] = trans[now.way][0];
            mymap[target_x][target_y] = trans[now.way][1];
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 4; ++j) {
                    int x = now.x+dir[j][0], y = now.y+dir[j][1];
                    if (i == 1) {
                        x += dir[now.way][0];
                        y += dir[now.way][1];
                    }
                    check(x, y);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mymap[i][j] == '.') {
                cout << "Not unique" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << mymap[i] << endl;
    }
    return 0;
}
