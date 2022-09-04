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

vector<int> solution(int n, int s) {
    
    if (n > s) return {-1};
    
    vector<int> ans(n, s/n);
    for (int i=0; i<s%n; i++)
        ans[n-1-i] += 1;
    return ans;
}