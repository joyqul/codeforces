#include <iostream>
#include <cmath>

using namespace std;

double dis(long long x, long long y) {
    return sqrt(x*x + y*y);
}

int main () {
    int n;
    cin >> n;
    int x = 0, y = n;
    long long ans = 0;
    while (y) {
        double len = dis(x, y);
        if (x > y)
    }
    if (ans) cout << ans*4 << endl;
    else cout << 1 << endl;
    
    return 0;
}
