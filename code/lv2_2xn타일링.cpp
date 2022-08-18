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
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

using namespace std;

int solution(int n) {
    
    int dp[60005];
    
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<=n; i++) 
        dp[i] = (dp[i-1]+dp[i-2])%1000000007;
    return dp[n];
}