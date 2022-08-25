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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int solution(int N, vector<vector<int>> road, int K) {
    
    vector<vector<int>> dp(N+1, vector<int>(N+1, 1000000000));
    
    for (int i=1; i<=N; i++) dp[i][i] = 0;
    for (auto v : road) {
        int a = v[0], b = v[1], c = v[2];
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }
    
    //Floyd
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
        }
    }
    
    int cnt = 0;
    for (int i=1; i<=N; i++) 
        if (dp[1][i] <= K) cnt++;

    return cnt;
}