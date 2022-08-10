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

long long solution(int n) {
    
    long long dp[2005] = {0};
    
    dp[1] = 1; dp[2] = 2;
    for (int i=3; i<=n; i++) 
        dp[i] = (dp[i-1]+dp[i-2])%1234567;
    return dp[n];
}