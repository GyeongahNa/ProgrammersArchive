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

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

bool check(int mid, vector<int> stones, int k) {
    
    //mid-1까지 징검다리를 건넜을 때 상태
    int sz = stones.size();
    for (int i=0; i<sz; i++)
        stones[i] = max(0, stones[i]-(mid-1));
    
    //연속하는 0의 개수가 k개 초과 이면 false 리턴
    int idx = 0;
    while (idx < sz) {
        if (stones[idx]) idx++;
        else {
            int cnt = 0;
            while (idx < sz && !stones[idx]) {
                cnt++;
                idx++;
            } 
            if (cnt+1 > k) return false;
        }
    }
    return true;
}

int binarySearch(const vector<int>& stones, int k) {
    
    int first = 1;
    int last = 200000000;
    int ret = 1;
    
    while (first <= last) {
        int mid = (first+last)/2;
        if (check(mid, stones, k)) {
            ret = mid;
            first = mid+1;
        }
        else last = mid-1;
    }
    return ret;
}

int solution(vector<int> stones, int k) {
    
    return binarySearch(stones, k);
}