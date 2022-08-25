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
#define MOD 1000000007

int solution(int n) {
    
    vector<long long> dp(5005, 0);
    
    dp[0] = 1; dp[2] = 3;
    for (int i=4; i<=n; i+=2) {
        dp[i] = 3*dp[i-2];
        for (int j=i-4; j>=0; j-=2)
            dp[i] += 2*dp[j];
        dp[i] %= MOD;
    }
    return dp[n];
}