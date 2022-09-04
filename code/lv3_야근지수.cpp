#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
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

long long solution(int n, vector<int> works) {
    
    priority_queue<int, vector<int>, less<int>> pq;
    for (auto x : works) pq.push(x);
    
    for (int i=0; i<n; i++) {
        if (pq.empty()) continue;
        int cur = pq.top();
        pq.pop();
        if (--cur) pq.push(cur);
    }
    
    long long ans = 0;
    while (!pq.empty()) {
        long long cur = pq.top();
        pq.pop();
        ans += cur*cur;
    }
    return ans;
}