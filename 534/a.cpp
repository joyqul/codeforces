#include <bits/stdc++.h>

using namespace std;

void solve(int people) {
    int remain = people;
    for (int i = 1; i < people; ++i) {
        cout << i << " ";
        --remain;
        if (remain == 4) {
            remain = i+1;
            break;
        }
        cout << people-i+1 << " ";
        --remain;
        if (remain == 4) {
            remain = i+1;
            break;
        }
    }
    cout << remain+1 << " " << remain+3 << " " << remain << " " << remain+2 << endl;
}

int main () {
    int people;
    scanf("%d", &people);
    if (people <= 2) {
        cout << 1 << endl << "1" << endl; 
    }
    else if (people == 3) {
        cout << 2 << endl << "1 3" << endl;
    }
    else if (people == 4) {
        cout << 4 << endl << "2 4 1 3" << endl;
    }
    else {
        cout << people << endl;
        solve(people);
    }
    return 0;
}
