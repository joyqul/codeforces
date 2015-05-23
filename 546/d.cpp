#include <bits/stdc++.h>

using namespace std;
map<int, int> record;
bool is_prime[5000000];

void make_prime() {
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i < 5000000; ++i) {
        if (!is_prime[i]) continue;
        int next = i*2;
        while (next < 5000000) {
            is_prime[next] = false;
            next += i;
        }
    }
    for (int i = 2; i < 5000000; ++i) {
        if (is_prime[i]) record[i] = 0;
    }
}

void init() {
    for (map<int, int>::iterator it = record.begin(); it != record.end(); ++it) {
        it->second = 0;
    }
}

void cal(int num) {
    for (map<int, int>::iterator it = record.begin(); it != record.end(); ++it) {
        if (num == 1) return;
        int target = it->first;
        while (num%target == 0) {
            num /= target;
            ++(it->second);
        }
    }
}

void play(int st, int ed) {
    if (st == ed) {
        cout << 0 << endl;
        return;
    }
    ++st;
    while (st <= ed) {
        cal(st);
        ++st;
    }
    int ans = 0;
    for (map<int, int>::iterator it = record.begin(); it != record.end(); ++it) {
        ans += it->second;
    }
    cout << ans << endl;
}

int main () {
    make_prime();
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        int st, ed;
        scanf("%d%d", &ed, &st);
        play(st, ed);
    }
    return 0;
}
