#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
double probability[100];

double maxi(double a, double b) {
    return a>b? a: b;
}

int main () {
    int number;
    cin >> number;
    for (int i = 0; i < number; ++i)
        cin >> probability[i];

    sort(probability, probability+number);

    if (probability[number-1] >= 0.5) {
        printf("%.12lf\n", probability[number-1]);
    }
    else {
        double max = 0, product = 1;
        for (int first = number - 1; first >=0; --first) {
            double result = 0;
            product *= (1 - probability[first]);
            for (int st = first; st < number; ++st) {
                result += (product/(1-probability[st])) * probability[st];
            }
            max = maxi(max, result);
        }
        printf("%.12lf\n", max);
    }
    
    return 0;
}
