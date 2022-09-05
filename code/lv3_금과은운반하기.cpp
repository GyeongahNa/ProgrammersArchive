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
using l = long long;

#define X first
#define Y second

bool check(l k, int a, int b, const vector<int>& g, const vector<int>& s, const vector<int>& w, const vector<int>& t) {
    
    l totalg = 0, totals = 0, total = 0;
    for (int i=0; i<(int)g.size(); i++) {
        l rt = t[i]*2;
        l n = k/rt;
        if (k%rt >= t[i]) n++;
        totalg += min(w[i]*n, 1LL*g[i]);
        totals += min(w[i]*n, 1LL*s[i]);
        total += min(w[i]*n, 1LL*g[i]+s[i]);
    }
    
    return totalg >= a && totals >= b && total >= a+b;
}

l binarySearch(int a, int b, const vector<int>& g, const vector<int>& s, const vector<int>& w, const vector<int>& t) {
    
    l first = 0;
    l last = 4*1e14+1e5;    
    l ret = last;
    
    while (first <= last) {
        l mid = (first+last)/2;
        if (check(mid, a, b, g, s, w, t)) {
            ret = mid;
            last = mid-1;
        }
        else first = mid+1;
    }
    return ret;
}


long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    
    return binarySearch(a, b, g, s, w, t);
}