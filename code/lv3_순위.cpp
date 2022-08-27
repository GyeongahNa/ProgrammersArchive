#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int solution(int n, vector<vector<int>> results) {
    
    vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
    
    //floyd
    for (auto v : results) {
        int a = v[0];
        int b = v[1];
        dp[a][b] = true;
    }
    
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++)
                if (dp[i][k] && dp[k][j]) dp[i][j] = true;
        }
    }
    
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        int nwin = 0;
        int nloss = 0;
        for (int j=1; j<=n; j++) {
            if (dp[i][j]) nwin++;
            if (dp[j][i]) nloss++;
        }
        if (nwin+nloss == n-1) cnt++;
    }
    return cnt;
}