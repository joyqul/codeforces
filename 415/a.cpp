#include <iostream>
#include <cstdio>
#define MAX 100

using namespace std;

int light[MAX];

void init() {
    for (int i = 0; i< MAX; ++i)
        light[i] = -1;
}

int main () {
    int m, n;
    cin >> m >> n;
    init();
    while (n--) {
        int button;
        cin >> button;
        for (int i = button - 1; i < m; ++i)
            if (light[i] == -1) light[i] = button;

    }

    cout << light[0];

    for (int i = 1; i < m; ++i)
        cout << " " << light[i];
    
    cout << endl;
    
    return 0;
}
