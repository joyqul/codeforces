#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 2005

using namespace std;

struct NODE {
    int num, weight;
} difficult[MAX];

int n;
int first[MAX], second[MAX], third[MAX];

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

    bool has_second = false, has_third = false;
    for (int i = 0; i < n; ++i) {
        if (has_second && has_third) {
            first[i] = second[i] = third[i] = difficult[i].num;
        }
        else if (i+1 < n && difficult[i].weight == difficult[i+1].weight) {
            if (has_second) {
                has_third = true;
                first[i] = second[i] = third[i+1] = difficult[i].num;
                first[i+1] = second[i+1] = third[i] = difficult[i+1].num;
                ++i;
            }
            else {
                if (i+2 < n && difficult[i].weight == difficult[i+2].weight) {
                    has_second = has_third = true;
                    first[i] = second[i+1] = third[i] = difficult[i].num;
                    first[i+1] = second[i] = third[i+2] = difficult[i+1].num;
                    first[i+2] = second[i+2] = third[i+1] = difficult[i+2].num;
                    i += 2;
                }
                else {
                    has_second = true;
                    first[i] = second[i+1] = third[i] = difficult[i].num;
                    first[i+1] = second[i] = third[i+1] = difficult[i+1].num;
                    ++i;
                }
            }
        }
        else {
            first[i] = second[i] = third[i] = difficult[i].num;
        }
    }

    if (has_third) {
        cout << "YES" << endl;
        cout << first[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << first[i];
        }
        cout << endl;

        cout << second[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << second[i];
        }
        cout << endl;

        cout << third[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << third[i];
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
