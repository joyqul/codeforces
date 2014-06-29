#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100000

using namespace std;

int num[MAX+1];
vector<int> dis[MAX+1];

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &num[i]);

    for (int i = 0; i < m; ++i) {
        if (i != 0 && num[i] != num[i-1]) dis[num[i]].push_back(num[i-1]);
        if (i != m-1 && num[i] != num[i+1]) dis[num[i]].push_back(num[i+1]);
    }

    long long sum = 0, maximun = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dis[i].size()) continue;
        sort(dis[i].begin(), dis[i].end());
        int mid = dis[i][dis[i].size()/2];
        long long before = 0, after = 0;
        for (int j = 0, k = dis[i].size(); j < k; ++j) {
            before += abs(i - dis[i][j]);
            after += abs(mid - dis[i][j]);
        }
        sum += before;
        maximun = max(maximun, before - after);
    }

    cout << sum/2 - maximun << endl;
    return 0;
}
