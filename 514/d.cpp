#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct SegmentTree{

	int rank, capacity, length;
	int *input, *tree;

    SegmentTree() {}
	void init(int* input, int length){
		this->input = input;
		this->length = length;
		rank = 1;
		while((1<<rank++) < length);
		capacity = 1<<(rank-1);
		tree = new int[capacity << 1];
		build(1, capacity, capacity<<1);
	}

	~SegmentTree(){
        delete[] tree;
	}

	int build(int index, int left, int right){
		if(index >= left){
			return tree[index] = getInput(index);
		}
		int middle = (left+right) >> 1;
		int left_value = build(lc(index), left, middle);
		int right_value = build(rc(index), middle, right);
		return tree[index] = max(left_value, right_value);
	}

	int query(int start, int finish){
		return query(1, capacity, capacity<<1, capacity+start, capacity+finish+1);
	}

	int query(int index, int left, int right, int start, int finish){
		if(left == start && right == finish) return tree[index];
		int middle = (left+right) >> 1;
		if(finish <= middle) return query(lc(index), left, middle, start, finish);
		if(start >= middle) return query(rc(index), middle, right, start, finish);
		int left_value = query(lc(index), left, middle, start, middle);
		int right_value = query(rc(index), middle, right, middle, finish);
		return max(left_value, right_value);
	}

	int getInput(int index){
		index -= capacity;
		if(index < length) return input[index];
		return 0;
	}

	int lc(int x){
		return x<<1;
	}

	int rc(int x){
		return (x<<1)+1;
	}
};

int n, m, k;
SegmentTree SegTree[5];
int base[5][100010];
int ans[5];

bool legal(int len) {
    int tmp[m];
    for (int i = 0; i+len <= n; ++i) {
        int used = 0;
        for (int j = 0; j < m; ++j) {
            tmp[j] = SegTree[j].query(i, i+len-1);
            used += tmp[j];
        }
        if (used <= k) {
            for (int j = 0; j < m; ++j) ans[j] = tmp[j];
            return true;
        }
    }
    return false;
}

int main () {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &base[j][i]);
        }
    }
    for (int i = 0; i < m; ++i) {
        SegTree[i].init(base[i], n);
    }
    memset(ans, 0, sizeof(ans));
    int len = n;
    int now = 0;
    while (len) {
        if (now+len <= n && legal(now+len)) now += len;
        else len /= 2;
    }
    cout << ans[0];
    for (int i = 1; i < m; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}
