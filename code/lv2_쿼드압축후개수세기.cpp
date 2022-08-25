#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

bool check(int x, int y, int n, const vector<vector<int>>& arr) {
    
    for (int i=x; i<x+n; i++) {
        for (int j=y; j<y+n; j++) {
            if (arr[i][j] != arr[x][y]) return false;
        }
    }
    return true;
}

void func(int x, int y, int n, vector<int>& cnt, const vector<vector<int>>& arr) {
    
    if (check(x, y, n, arr)) {
        cnt[arr[x][y]]++;
        return ;
    }
    
    func(x, y, n/2, cnt, arr);
    func(x, y+n/2, n/2, cnt, arr);
    func(x+n/2, y, n/2, cnt, arr);
    func(x+n/2, y+n/2, n/2, cnt, arr);
}

vector<int> solution(vector<vector<int>> arr) {
    
    int n = arr.size();
    vector<int> cnt(2, 0);
    func(0, 0, n, cnt, arr);
    return cnt;
}