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

int solution(vector<vector<int>> board) {
    
    int H = board.size();
    int W = board[0].size();
    vector<vector<int>> dp(H, vector<int>(W, 0));
    
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (i == 0 || j == 0) dp[i][j] = board[i][j]; 
            else if (!board[i][j]) continue;
            else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
        }
    }

    int mx = 0;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++)
            mx = max(dp[i][j], mx);
    }
    return mx*mx;
}