#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int lowbit(int x) {
    if ( x == 0 ) return 0;
    int ans = 1;
    while(x) {
        if ( (x & 1) == 1 ) return ans;
        x >>= 1;
        ans <<= 1;
    }
    return ans;
}

bool func(pair<int, int> x, pair<int, int> y) {
    return x.first > y.first;
}

int main () {
    int sum, limit;
    scanf("%d%d", &sum, &limit);
    vector<pair<int, int> > num;
    for (int i = 1; i <= limit; ++i)
        num.push_back( make_pair(lowbit(i), i) );
    sort(num.begin(), num.end(), func);

    queue<int> ans;
    for (int i = 0; i < limit; ++i) {
        int tmp = num[i].first;
        if (tmp <= sum) {
            sum -= tmp;
            ans.push(num[i].second);
        }
        if (sum == 0) break;
    }

    if (sum != 0)
        printf("-1\n");
    else {
        cout << ans.size() << endl;
        for (int i = 1, j = ans.size(); i < j; ++i) {
            printf("%d ", ans.front());
            ans.pop();
        }
        printf("%d\n", ans.front());
    }
    return 0;
}
