#include <iostream>
#include <map>

using namespace std;

map<string, int> cards;
map<int, bool> has;
string contain[] = {"R1", "R2", "R3", "R4", "R5",
                    "G1", "G2", "G3", "G4", "G5",
                    "B1", "B2", "B3", "B4", "B5",
                    "Y1", "Y2", "Y3", "Y4", "Y5",
                    "W1", "W2", "W3", "W4", "W5"};

char ways[] = {'R', 'G', 'B', 'Y', 'W',
               '1', '2', '3', '4', '5'};

int mini(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    return a < b? a: b;
}

bool check(bool print=false) {
    has.clear();
    for (int i = 0; i < 25; ++i) {
        string this_card = contain[i];
        int color = cards[this_card];
        if (color) {
            if (print) cout << "color: " << color << " this_card: " << this_card << endl;
            if (has[color]) {
                if (print) cout << endl;
                return false;
            }
            has[color] = true;
        }
        else continue;
    }
    if (print) cout << endl;
    return true;
}

void colored(int x) {
    for (int i = 0; i < 25; ++i) {
        string this_card = contain[i];
        char ch = ways[x];
        if (cards[this_card] != 0) {
            if (ch == this_card[0] || ch == this_card[1]) 
                cards[this_card] |= (1 << (x+1));
        }
        else continue;
    }
}

void uncolored(int x) {
    for (int i = 0; i < 25; ++i) {
        string this_card = contain[i];
        char ch = ways[x];
        if (cards[this_card] != 0) {
            if (ch == this_card[0] || ch == this_card[1]) 
                cards[this_card] &= ~(1 << (x+1));
        }
        else continue;
    }
}

int query(int i, bool done, int times) {
    if (i == 10) {
        if (check()) return times;
        else return -1;
    }

    if (done) {
        colored(i);
        ++times;
    }

    int ans =  mini(query(i+1, true, times), query(i+1, false, times));

    if (done) {
        uncolored(i);
        --times;
    }
    return ans;
}

int query() {
    if (check()) return 0;
    return mini(query(0, true, 0), query(0, false, 0));
}

int main () {
    int number;
    cin >> number;
    for (int i = 0; i < number; ++i) {
        string this_card;
        cin >> this_card;
        cards[this_card] = 1;
    }

    cout << query() << endl;
    
    return 0;
}
