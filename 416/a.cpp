#include <iostream>
#include <cstdio>

using namespace std;

int main () {
    int cases;
    while (scanf("%d", &cases) != EOF) {
        long long up_limit = 0, down_limit = 0;
        bool up = false, down = false;
        while (cases--) {
            string symbol;
            getchar();
            getline(std::cin, symbol, ' ');
            long long target;
            cin >> target;
            char condition;
            scanf(" %c", &condition);
            if (condition == 'N') {
                if (symbol == ">")
                    symbol = "<=";
                else if (symbol == ">=")
                    symbol = "<";
                else if (symbol == "<")
                    symbol = ">=";
                else 
                    symbol = ">";
            }
            
            if (symbol == ">" || symbol == ">=") {
                if (symbol == ">")
                    ++target;

                if (down && target > down_limit)
                    down_limit = target;
                else if (!down) {
                    down_limit = target;
                    down = true;
                }
            }
            else {
                if (symbol == "<")
                    --target;
                if (up && target < up_limit)
                    up_limit = target;
                else if (!up) {
                    up_limit = target;
                    up = true;
                }
            }
        }

        if (!up)
            cout << down_limit << endl;
        else if (!down)
            cout << up_limit << endl;
        else if (up_limit < down_limit)
            cout << "Impossible" << endl;
        else cout << down_limit << endl;
    }
    
    return 0;
}
