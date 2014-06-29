#include <iostream>
#include <cstdio>

using namespace std;

int maxi(int a, int b) {
    return a > b? a: b;
}

int main () {
    string input;
    cin >> input;
    int add;
    scanf("%d", &add);
    int total_size = input.size() + add;

    int max_len = 0;
    for (int first = 0; first < total_size; ++first) {
        for (int end = total_size - 1; end > first; --end) {
            for (int pattern = (end - first + 1)/2; pattern > 0; --pattern) {
                bool sucess = true;
                int tmp_end = 0;
                for (int i = 0; i < pattern; ++i) {
                    if (first + pattern + i >= input.size()) break;
                    if (input[first+i] != input[first+pattern+i]) {
                        sucess = false;
                        tmp_end = first + pattern + i -1;
                        break;
                    }
                }
                if (sucess)
                    max_len = maxi(max_len, pattern * 2);
            }
        }
    }

    cout << max_len << endl;
    
    return 0;
}
