#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int apples;
    scanf("%d", &apples);
    int a = 0, b = 0;
    for (int i = 0; i < apples; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 100)
            ++a;
        else
            ++b;
    }
    b = b % 2;
    if (b == 0 && a % 2 == 0)
        printf("YES\n");
    else if (b == 0) 
        printf("NO\n");
    else if (a < 2)
        printf("NO\n");
    else if ((a - 2) % 2 == 1)
        printf("NO\n");
    else
        printf("YES\n");
}
