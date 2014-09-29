#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 2005

using namespace std;

struct NODE {
    int num, weight;
} difficult[MAX];
int n;

bool cmp(NODE a, NODE b) {
    return a.weight < b.weight;
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &difficult[i].weight);
        difficult[i].num = i+1;
    }
    sort(difficult, difficult+n, cmp);
    int way = 1, pre = 1;
    for (int i = 1; i < n; ++i) {
        if (difficult[i].weight == difficult[i-1].weight) ++pre;
        else {
            way *= pre;
            pre = 1;
        }
    }
    way *= pre;
    if (way >= 3) {
        cout << "YES" << endl;
        // first, origin
        cout << difficult[0].num;
        for (int i = 1; i < n; ++i) {
            cout << " " << difficult[i].num;
        }
        cout << endl;

        // second
        if (difficult[0].weight == difficult[1].weight) {
            cout << difficult[1].num << " " << difficult[0].num;
            for (int i = 2; i < n; ++i) {
                cout << " " << difficult[i].num;
            }
            cout << endl;
        }
        else {
            cout << difficult[0].num;
            int i;
            for (i = 1; i < n-1; ++i) {
                if (difficult[i].weight == difficult[i+1].weight) {
                    cout << " " << difficult[i+1].num << " " << difficult[i].num;
                    break;
                }
                cout << " " <<  difficult[i].num;
            }
            i += 2;
            while (i < n) {
                cout << " " << difficult[i].num;
                ++i;
            }
            cout << endl;
        }

        // third
        int i;
        cout << difficult[0].num;
        for (i = 1; i < n; ++i) {
            cout << " " << difficult[i].num;
            if (difficult[i].weight == difficult[i-1].weight) {
                break;
            }
        }
        i += 2;
        for (; i < n; ++i) {
            if (difficult[i].weight == difficult[i-1].weight) {
                cout << " " << difficult[i].num << " " << difficult[i-1].num;
                ++i;
                break;
            }
            cout << " " << difficult[i-1].num;
        }
        for (; i < n; ++i) {
            cout << " " << difficult[i].num;
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
