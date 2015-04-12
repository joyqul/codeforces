#include <bits/stdc++.h>
using namespace std;

int key[26];
int main () {
    int times;
    memset(key, 0, sizeof(key));
    scanf("%d", &times);
    char input[200005];
    scanf("%s", input);
    int ans = 0;
    for (int i = 0; i < times-1; ++i) {
        key[input[i*2]-'a']++;
        int target = input[i*2+1] - 'A';
        if (key[target] == 0) ++ans;
        else --key[target];
    }
    cout << ans << endl;
    return 0;
}
