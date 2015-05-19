#include <bits/stdc++.h>
using namespace std;

int dice[200005];

int main () {
    long long total = 0;

    long long dice_num, target;
    cin >> dice_num >> target;
    for (int i = 0; i < dice_num; ++i) {
        scanf("%d", &dice[i]);
        total += dice[i];
    }
    
    long long ans = 0;
    for (int i = 0; i < dice_num; ++i) {
        if (dice[i] > target-dice_num+1) ans += (dice[i]-target+dice_num-1);
        if (total-dice[i] < target) ans += (target-total+dice[i]-1);
        if (i!=0) cout << " ";
        cout << ans;
        ans = 0;
    }
    cout << endl;

    return 0;
}
