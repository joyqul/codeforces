#include <bits/stdc++.h>
using namespace std;

int times[200005];
bool same[200005];

void mirro(string& str, int x) {
    cout << str[str.size()-x-1];
}

int main () {
    memset(same, true, sizeof(same));
    string input;
    cin >> input;
    int days;
    scanf("%d", &days);
    while (days--) {
        int target;
        scanf("%d", &target);
        ++times[target-1];
    }
    int now = 0;
    for (int i = 0; i < input.size()/2; ++i) {
        now += times[i];
        if (now%2 == 0) {
            cout << input[i];
            same[i] = true;
        }
        else {
            mirro(input, i);
            same[i] = false;
        }
    }
    for (int i = input.size()/2; i < input.size(); ++i) {
        if (same[input.size()-1-i]) cout << input[i];
        else mirro(input, i);
    }
    cout << endl;
    return 0;
}
