#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        bool collision = false;
        for (int j = 0; j < n; ++j) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp == 1 || tmp == 3) collision = true;
        }
        if (!collision) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    if (ans.size()) cout << ans[0];
    for (int i = 1; i < ans.size(); ++i) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}
