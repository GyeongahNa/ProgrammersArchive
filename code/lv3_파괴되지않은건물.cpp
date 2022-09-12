#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
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

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> pfx(n+1, vector<int>(m+1, 0));
    
    for (const auto& v : skill) {
        int type = v[0], r1 = v[1], c1 = v[2], r2 = v[3], c2 = v[4], d = v[5];
        if (type == 1) d *= -1;
        pfx[r1][c1] += d;
        pfx[r1][c2+1] += -d;
        pfx[r2+1][c1] += -d;
        pfx[r2+1][c2+1] += d;
    }
    
    for (int i=0; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            pfx[i][j] += pfx[i][j-1];
        }
    }
    
    for (int j=0; j<=m; j++) {
        for (int i=1; i<=n; i++) {
            pfx[i][j] += pfx[i-1][j];
        }
    }
    
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            board[i][j] += pfx[i][j];
            if (board[i][j] >= 1) cnt++;
        }
    }
    
    return cnt;
}