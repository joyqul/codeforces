#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 300005

using namespace std;
int contain[MAX];
int n;

bool cmp(const int x, const int y) {
    return x<y;
}

void print() {
    for (int i = 0; i < n; ++i)
        cout << contain[i] << " ";
    cout << endl;
}

int main () {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &contain[i]);

    sort(contain, contain+n, cmp);

    long long ans = 0;
    
    if (n == 1) {
        cout << contain[0] << endl;
    }
    else {
        for (long long i = 0; i < (n-2); ++i) 
            ans = ans + (i+2)*contain[i];
        ans = ans + n*(long long)(contain[n-2] + contain[n-1]);
        cout << ans << endl;
    }
    
    return 0;
}
