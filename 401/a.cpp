#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int num, max;
    scanf("%d%d", &num, &max);
    int sum = 0, input = 0;
    for (int i = 0; i < num; ++i) {
        scanf("%d", &input);
        sum += input;
    }

    if (sum < 0) sum = -sum;
    cout << sum/max + (sum%max?1:0) << endl;
    
    return 0;
}
