#include <cstdio>
#include <cstring>
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

int dp[100005];

int solution(int n, vector<int> money) {
    
    dp[0] = 1;
    for (int i=0; i<(int)money.size(); i++) {
        for (int j=money[i]; j<=n; j++) {
            dp[j] += dp[j-money[i]];
            dp[j] %= MOD;
        }
    }
    
    return dp[n];
}