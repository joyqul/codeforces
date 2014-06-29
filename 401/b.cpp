#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    bool input[4000];
    for (int i = 0; i < 4000; ++i)
        input[i] = false;

    int max, atend;
    scanf("%d%d", &max, &atend);
    --max;

    for (int i = 0; i < atend; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 2) {
            int a;
            scanf("%d", &a);
            input[a-1] = true;
        }
        else {
            int a, b;
            scanf("%d%d", &a, &b);
            input[a-1] = true;
            input[b-1] = true;
        }
    }

    int max_miss = 0, min_miss= 0;
    for (int i = 0; i < max; ++i) {
        if (!input[i]) {
            ++max_miss;
            ++min_miss;
            if (i+1 < max && !input[i+1]) {
                ++max_miss;
                ++i;
            }
        }
    }

    cout << min_miss << " " << max_miss << endl;

    return 0;
}
