#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int sequence[3005];
vector<pair<int, int> >change;
queue<int> not_change;

int find_swap(int num) {
    int times = 0;
    for (int i = 0; i <num; ++i) {
        int now_num = sequence[i];
        int target_num = sequence[now_num-1];
        if (now_num != target_num) {
            ++times;
            int tmp = sequence[sequence[i]-1];
            change.push_back(make_pair(min(tmp, sequence[i]), max(tmp, sequence[i])));
            sequence[sequence[i]-1] = sequence[i];
            sequence[i] = tmp;
        }
        else not_change.push(now_num);
    }
    return times;
}

bool func(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first? true: (a.second < b.second? true: false);
}

int main () {
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> sequence[i];
    }
    int target;
    cin >> target;

    int need_swap = find_swap(num);
    if (need_swap == target) cout << "0" << endl;
    else if (need_swap > target) {
        int times = need_swap - target;
        cout << times << endl;
        sort(change.begin(), change.end(), func);
        for (int i = 1; i < times; ++i)
            cout << change[i-1].first << " " << change[i-1].second << " ";
        cout << change[times-1].first << " " << change[times-1].second << endl;
    }
    else {
        int times = target - need_swap;
        cout << times << endl;
        int first = not_change.front();
        not_change.pop();
        while (times != 1) {
            int tmp = not_change.front();
            not_change.pop();
            cout << first << " " << tmp << " ";
            --times;
        }
        int tmp = not_change.front();
        not_change.pop();
        cout << first << " " << tmp << endl;
    }
    
    return 0;
}
