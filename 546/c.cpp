#include <bits/stdc++.h>

using namespace std;

map<pair<long long, long long>, int> record;
int n, a, b;

struct NODE {
    queue<int> input;
    long long mystate;
    NODE() : mystate(0) {}
} node[2];

long long power(int times) {
    long long ans = 1;
    while (times--) ans*=10;
    return ans;
}

void play() {
    int times = 1;
    pair<long long, long long> now = make_pair(node[0].mystate, node[1].mystate);
    while (record.count(now) == 0) {
        record[now] = 1;
        int one = node[0].input.front(), two = node[1].input.front();
        node[0].input.pop();
        node[1].input.pop();
        node[0].mystate -= one*power(node[0].input.size());
        node[1].mystate -= two*power(node[1].input.size());
        if (one < two) {
            node[1].mystate = node[1].mystate*100 + one*10 + two;
            node[1].input.push(one);
            node[1].input.push(two);
        }
        else {
            node[0].mystate = node[0].mystate*100 + two*10 + one;
            node[0].input.push(two);
            node[0].input.push(one);
        }
        if (node[1].input.size() == 0) {
            cout << times << " " << 1 << endl;
            return;
        }
        if (node[0].input.size() == 0) {
            cout << times << " " << 2 << endl;
            return;
        }
        now = make_pair(node[0].mystate, node[1].mystate);
        ++times;
    }
    cout << -1 << endl;
}

int main () {
    cin >> n;
    for (int i = 0; i < 2; ++i) {
        cin >> a;
        for (int j = 0; j < a; ++j) {
            long long tmp;
            cin >> tmp;
            node[i].mystate = node[i].mystate*10+tmp;
            node[i].input.push(tmp);
        }
    }
    play();
    return 0;
}
