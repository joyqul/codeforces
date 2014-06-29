#include <iostream>

using namespace std;

int main () {
    bool alpha[26];
    for (int i = 0; i < 26; ++i)
        alpha[i] = false;

    char ch;
    while (1) {
        cin >> ch;
        if (ch == '}') break;
        if (ch >= 'a' && ch <= 'z')
            alpha[ch - 'a'] = true;
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i)
        if (alpha[i]) ++ans;
    cout << ans << endl;
   
    return 0;
}
