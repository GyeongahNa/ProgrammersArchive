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
#include <cctype>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dp[505][505];

int solution(vector<vector<int>> triangle) {
    
    int r = triangle.size();
    for (int i=0; i<r; i++) {
        for (int j=0; j<i+1; j++) {
            if (j >= 1) dp[i][j] = dp[i-1][j-1];
            if (j+1 <= i) dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] += triangle[i][j];
        }
    }
    
    int mx = 0;
    for (int i=0; i<r; i++) 
        mx = max(mx, dp[r-1][i]);
    return mx;
}