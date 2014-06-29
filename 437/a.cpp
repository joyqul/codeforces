#include <iostream>
#include <cstdio>

using namespace std;

bool judge(int a, int b, int c, int d) {
    if (a >= 2*b && a >= 2*c && a >= 2*d)
        return true;
    if (a <= b/2 && a <= c/2 && a <= d/2)
        return true;
    return false;
}

int main () {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int size[] = { a.size() - 2, b.size() - 2, c.size() - 2, d.size() - 2 };
    bool ans[] = { judge(size[0], size[1], size[2], size[3]),
                   judge(size[1], size[0], size[2], size[3]),
                   judge(size[2], size[1], size[0], size[3]),
                   judge(size[3], size[1], size[2], size[0]) };
    
    if (ans[0] & !ans[1] & !ans[2] &!ans[3])
        printf("A\n"); 
    else if (!ans[0] & ans[1] & !ans[2] &!ans[3])
        printf("B\n"); 
    else if (!ans[0] & !ans[1] & !ans[2] &ans[3])
        printf("D\n"); 
    else
        printf("C\n"); 
        
    return 0;
}
