#include <iostream>
#include <cstdio>

using namespace std;
long long n;

long long cards(long long x) {
    return ( (x+1)*x / 2 * 3 ) - x;
}

long long binary_search() {
    long long now = 0, step = 1e5;
    while (step > 0) {
        long long target = cards(now + step);
        if (target < n) now += step;
        else if (target == n) return now+step;
        else step /= 2;
    }
    return now;
}

void find() {
    long long ans = 0;
    long long max_level = binary_search();
    for (int i = 0; i < 3 && max_level-i > 0; ++i) {
        long long full = cards(max_level-i);
        long long last = full - n;
        if (last%3 == 0) {
            ans += ( (max_level-i-1)/3 + 1);
        }
    }
    cout << ans << endl;
}

int main () {
    cin >> n;
    find();
    return 0;
}
