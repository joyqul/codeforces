#include <iostream>

using namespace std;

int main () {
    long long n, a, b;
    cin >> n >> a >> b;
    while (n--) {
        long long token;
        cin >> token;
        cout << ((token * a) % b)/a;
        if (n != 0) cout << " ";
    }
    cout << endl;
    return 0;
}
