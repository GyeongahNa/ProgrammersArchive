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

int flag;
vector<bool> fix(20, false);

void perm(int k, int mid, int cnt, int n, const vector<int>& weak, const vector<int>& dist) {
    
    if (k >= mid) {
        if (cnt >= (int)weak.size()) flag = true;
        return ;
    }
    
    for (int i=0; i<(int)weak.size(); i++) {
        if (fix[i]) continue;
        
        int nextcnt = cnt;
        vector<bool> tmp = fix;
        
        for (int j=0; j<(int)weak.size(); j++) {
            if (fix[j]) continue;
            if (i == j) {
                fix[j] = true;
                nextcnt++;
            }
            else if (i < j && weak[j]-weak[i] <= dist[k]) {
                fix[j] = true;
                nextcnt++;
            }
            else if (i > j && n-weak[i] + weak[j] <= dist[k]) {
                fix[j] = true;
                nextcnt++;
            }
        }
        
        perm(k+1, mid, nextcnt, n, weak, dist);
        fix = tmp;
    }
}

bool check(int mid, int n, const vector<int>& weak, const vector<int>& dist) {
    
    flag = false;
    perm(0, mid, 0, n, weak, dist);
    return flag;
}

int binarySearch(int n, const vector<int>& weak, const vector<int>& dist) {
    
    int first = 1;
    int last = (int)dist.size();
    int ret = -1;
    
    while (first <= last) {
        int mid = (first+last)/2;
        if (check(mid, n, weak, dist)) {
            ret = mid;
            last = mid-1;
        }
        else first = mid+1;
    }
    return ret;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    
    sort(dist.begin(), dist.end(), greater<>());
    return binarySearch(n, weak, dist);
}