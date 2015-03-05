#include <bits/stdc++.h>

const int MAX = 10010;

using namespace std;

struct SLOT {
    int start, end;
} slot[MAX];

int trans[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int change(char date[], char time[]) {
    int ans = 60*24*365*(date[3]-'3');
    int month = (date[5]-'0')*10 + (date[6]-'0');
    ans += trans[month-1]*24*60;
    if (date[3] == '6' && month > 2) ans += 24*60; // leap year
    int day = (date[8]-'0')*10 + (date[9]-'0');
    ans += (day-1)*60*24;
    int hour = (time[0]-'0')*10 + (time[1]-'0');
    int mins = (time[3]-'0')*10 + (time[4]-'0');
    ans += hour*60;
    ans += mins;
    //cout << "Change: " << date << " " << time << " to " << ans << endl;
    return ans;
}

vector<int> record;
map<int, int> discretization;
bool cmp(const int& x, const int& y) {
    return x<y;
}

void get_start(int code) {
    char rev[30];
    char date[20], time[20];
    scanf("%s%s%s", rev, date, time);
    slot[code].start = change(date, time);
    record.push_back(slot[code].start);
}

void get_end(int code, int clean_time) {
    char date[20], time[20];
    scanf("%s%s", date, time);
    slot[code].end = change(date, time)+clean_time;
    record.push_back(slot[code].end);
}

int main () {
    for (int i = 1; i <= 12; ++i) trans[i] += trans[i-1];
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        record.clear();
        int n, clean_time;
        scanf("%d%d", &n, &clean_time);
        for (int i = 0; i < n; ++i) {
            get_start(i);
            get_end(i, clean_time);
        }
        sort(record.begin(), record.end(), cmp);

        int pre = -1, id = 0;
        for (int i = 0; i < record.size(); ++i) {
            if (record[i] != pre) discretization[record[i]] = id++;
            pre = record[i];
        }
        int room[MAX];
        memset(room, 0, sizeof(room));
        for (int i = 0; i < n; ++i) {
            ++room[discretization[slot[i].start]];
            --room[discretization[slot[i].end]];
        }
        int maxi = 0, now = 0;
        for (int i = 0; i < MAX; ++i) {
            now += room[i];
            maxi = max(maxi, now);
        }
        cout << maxi << endl;
    }
    return 0;
}
