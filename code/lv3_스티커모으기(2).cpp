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
#include <climits>
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dp[100005][2][2];

int solution(vector<int> sticker) {

    int n = (int)sticker.size();
    if (n == 1) return sticker[0];

    dp[0][1][1] = sticker[0];

    for (int i=1; i<n; i++) {
        dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][0][1]);
        dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1]);
        dp[i][0][1] = dp[i-1][0][0] + sticker[i];
        dp[i][1][1] = dp[i-1][1][0] + sticker[i];
    }

    return max({dp[n-1][0][0], dp[n-1][0][1], dp[n-1][1][0]});
}