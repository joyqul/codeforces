#include <iostream>
#include <cstdio>

using namespace std;

int num[200005];

int main () {
    int size;
    while (scanf("%d", &size) != EOF) {
        for (int i = 0; i < size; ++i)
            scanf("%d", &num[i]);

        int ans = 0;
        int prev = 0;
        for (int i = 0; i < size; ++i) {
            if (num[i] == -1) {
                ++prev;
                continue;
            }
            bool first = true;
            int d = 0;
            for (int j = i + 1; j < size; ++j) {
                if (num[j] == -1) continue;
                if (first && ((num[j] - num[i]) % (j - i)) == 0) {
                    first = false;
                    d = (num[j] - num[i]) / (j - i);
                    if ((num[i] - d * prev) <= 0) {
                        ++ans;
                        prev = 0;
                    }
                    i = j;
                }
                else if (!first && (num[i] + d * (j - i) == num[j])) {
                    i = j;
                    continue;
                }
                else {
                    ++ans;
                    i = j;
                    prev = 0;
                    break;
                }
            }

        }
        cout << ans + 1 << endl;
    }
    return 0;
}
