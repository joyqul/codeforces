#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main () {
    char input[20];
    scanf("%s", input);
    int len = strlen(input);
    long long ans = 0;
    for (int i = 0; i < len; ++i) {
        int tmp = input[i] - '0';
        if ((9-tmp < tmp) && !(9-tmp == 0 && i == 0)) ans = ans*10 + 9-tmp;
        else ans = ans*10 + tmp;
    }
    cout << ans << endl;
    return 0;
}
