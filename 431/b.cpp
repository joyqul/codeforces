#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
    int happiness[5][5];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            scanf("%d", &happiness[i][j]);
    int people[] = {0, 1, 2, 3, 4};
    int max_cost = 0;
    do {
        int tmp = happiness[people[0]][people[1]] + happiness[people[1]][people[0]] +
            happiness[people[2]][people[3]] + happiness[people[3]][people[2]] +
            happiness[people[1]][people[2]] + happiness[people[2]][people[1]] +
            happiness[people[3]][people[4]] + happiness[people[4]][people[3]] +
            happiness[people[2]][people[3]] + happiness[people[3]][people[2]] +
            happiness[people[3]][people[4]] + happiness[people[4]][people[3]];
        if (tmp > max_cost)
            max_cost = tmp;
    } while (next_permutation(people, people + 5));
    printf("%d\n", max_cost);
    return 0;
}
