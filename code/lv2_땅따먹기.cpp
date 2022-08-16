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
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int solution(vector<vector<int>> land) {

    int N = land.size();
    int dp[1000000][4] = {0};

    for (int i=0; i<4; i++) dp[0][i] = land[0][i];
    for (int i=1; i<N; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                if (j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k]);
            }
            dp[i][j] += land[i][j];
        }
    }

    int mx = 0;
    for (int i=0; i<4; i++) mx = max(mx, dp[N-1][i]);
    return mx;
}