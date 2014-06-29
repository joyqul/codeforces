#include <iostream>

using namespace std;

int main () {
    string input;
    cin >> input;
    int n = 0, i = 0, e = 0, t = 0;
    for (int j = 0, k = input.size(); j < k; ++j) {
        if (input[j] == 'n') ++n;
        else if (input[j] == 'i') ++i;
        else if (input[j] == 'e') ++e;
        else if (input[j] == 't') ++t;
    }
    n = (n-1)/2;
    e /= 3;
    int ans = n;
    if (ans > i) ans = i;
    if (ans > e) ans = e;
    if (ans > t) ans = t;
    cout << ans << endl;
    return 0;
}
