#include <bits/stdc++.h>

using namespace std;

int main() {
    int len;
    scanf("%d", &len);
    string input;
    cin >> input;
    if (len < 26) {
        cout << "NO" << endl;
    }
    else {
        bool ch[26];
        memset(ch, false, sizeof(ch));
        for (int i = 0; i < len; ++i) {
            if (input[i] >= 'A' && input[i] <= 'Z') ch[input[i]-'A'] = true;
            else ch[input[i]-'a'] = true;
        }
        for (int i = 0; i < 26; ++i) {
            if (!ch[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
    }

    return 0;
}
