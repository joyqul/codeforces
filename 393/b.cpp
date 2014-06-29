#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    double a[171][171], b[171][171], w[171][171];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> w[i][j];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j >= i) break;
            double tmp = (w[i][j] + w[j][i])/2;
            a[i][j] = tmp;
            a[j][i] = tmp;
        }
        a[i][i] = w[i][i];
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i][j] = w[i][j] - a[i][j];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%8lf ", a[i][j]);
        cout << endl;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%8lf ", b
                    
                    
                    [i]
                    
                    
                    [j]);
    
    
    
    
    
    
        cout << endl;
    }
    return 0;
}
