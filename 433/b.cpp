#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 100005

using namespace std;

long long int origin_value[MAX], sort_value[MAX];

int main () {
    int num;
    scanf("%d", &num);
    long long int suffix = 0;
    origin_value[0] = sort_value[0] = 0; 
    for (int i = 1; i <= num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        suffix += tmp;
        origin_value[i] = suffix;
        sort_value[i] = tmp;
    }
    sort(sort_value, sort_value + num + 1);

    for (int i = 1; i <= num; ++i)
        sort_value[i] += sort_value[i-1];

    int query;
    scanf("%d", &query);
    for (int i = 0; i < query; ++i) {
        int type, begin, end;
        scanf("%d%d%d", &type, &begin, &end);
        if (type == 1) {
            cout << origin_value[end] - origin_value[begin-1] << endl;
        }
        else {
            cout << sort_value[end] - sort_value[begin-1] << endl;
        }
    }
    return 0;
}

