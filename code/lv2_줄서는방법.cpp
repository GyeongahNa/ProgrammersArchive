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

long long fac(int n) {
    if (n == 0) return 1;
    return n*fac(n-1);
}

vector<int> solution(int n, long long k) {
 
    k--;
    vector<int> v;
    for (int i=1; i<=n; i++) v.push_back(i);
    
    vector<int> ans;
    for (int i=n; i>=1; i--) {
        int idx = k/fac(i-1);
        ans.push_back(v[idx]);
        v.erase(v.begin()+idx);
        k = k%fac(i-1);
    }
    return ans;
}