#include <bits/stdc++.h>
#define INF 0x7fffffff

using namespace std;

struct NODE{
    int now, times;
} ;

int main () {
    int n, m;
    scanf("%d%d", &n, &m);

    NODE init;
    init.now = n;
    init.times = 0;

    queue<NODE> path;
    path.push(init);

    int ans = INF;

    bool visited[10001];
    memset(visited, false, sizeof(visited));
    while (path.size()) {
        NODE now = path.front();
        path.pop();

        if (now.now == m) {
            ans = min(ans, now.times);
            continue;
        }

        if (now.now < 10001) visited[now.now] = true;

        if (now.now > m) {
            ans = min(ans, now.times + now.now - m);
        }
        else {
            if (now.now - 1 > 0) {
                NODE tmp = now;
                --tmp.now;
                ++tmp.times;
                if (!visited[tmp.now]) {
                    visited[tmp.now] = true;
                    path.push(tmp);
                }
            }
            NODE tmp = now;
            tmp.now *= 2;
            ++tmp.times;
            if (tmp.now < 10001 && !visited[tmp.now]) {
                path.push(tmp);
            }
            else if (tmp.now > 10001) {
                path.push(tmp);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}

/*
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    NODE init;
    init.now = n;
    init.times = 0;
    queue<NODE> path;
    path.push(init);
    int ans = -1;

    bool visited[10001];
    memset(visited, false, sizeof(visited));

    while (path.size()) {
        NODE now = path.front();
        path.pop();

        if (now.now == m) {
            if (ans == -1) ans = now.now;
            else ans = min(ans, now.now);
            continue;
        }
        if (now.now < m) visited[now.now] = true;

        if (now.now > m) {
            if (ans == -1) ans = now.times + now.now-m;
            else ans = min(ans, now.times + now.now-m);
        }
        else if (now.now - 1 > 0) {
            NODE tmp = now;
            tmp.now -= 1;
            tmp.times++;
            if (!visited[tmp.now]) path.push(tmp);
            visited[tmp.now] = true;
        }

        if (now.now < m) {
            NODE tmp = now;
            tmp.now *= 2;
            tmp.times++;
            if (tmp.now >= m ) {
                path.push(tmp);
                continue;
            }

            if (!visited[tmp.now]) path.push(tmp);
            visited[tmp.now] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
*/
