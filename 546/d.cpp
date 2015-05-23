#include <bits/stdc++.h>

using namespace std;
bool is_prime[5000005];
int num[5000005];

inline int cal(int number) {
    for (int i = 2; i < number; ++i) {
        if (!is_prime[i]) continue;
        if (number%i != 0) continue;
        return 1 + (num[number/i]-num[number/i-1]);
    }
}

void make_prime() {
    memset(is_prime, true, sizeof(is_prime));
    memset(num, 0, sizeof(num));
    for (int i = 2; i < 5000005; ++i) {
        if (!is_prime[i]) continue;
        int next = i*2;
        while (next < 5000005) {
            is_prime[next] = false;
            next += i;
        }
    }

    for (int i = 2; i < 5000005; ++i) {
        if (is_prime[i]) num[i] = num[i-1]+1;
        else num[i] = num[i-1] + cal(i);
    }
}

inline void play(int st, int ed) {
    printf("%d\n", num[ed]-num[st]);
}

int main () {
    make_prime();
    int t;
    scanf("%d", &t);
    while (t--) {
        int st, ed;
        scanf("%d%d", &ed, &st);
        play(st, ed);
    }
    return 0;
}
