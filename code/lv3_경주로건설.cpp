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
#include <climits>
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, d, x, y;
int dist[4][30][30];

bool OOB(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

void setDist() {
    
    for (int k=0; k<4; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++)
                dist[k][i][j] = 1e9;
        }
    }
}

int cost(int bfd, int nowd) {
    
    if (bfd == nowd) return 100;
    return 600;
}

void bfs(const vector<vector<int>>& board) {
    
    queue<iii> q;
    
    for (int i=0; i<4; i++) {
        dist[i][0][0] = 0;
        q.push({i, 0, 0});
    }
    
    while (!q.empty()) {
        
        iii cur = q.front();
        tie(d, x, y) = cur;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (OOB(nx, ny) || board[x][y]) continue;
            if (dist[d][x][y] + cost(d, i) < dist[i][nx][ny]) {
                dist[i][nx][ny] = dist[d][x][y] + cost(d, i);
                q.push({i, nx, ny});
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    
    n = (int)board.size();
    setDist();
    bfs(board);
    
    int mn = 1e9;
    for (int i=0; i<4; i++) mn = min(mn, dist[i][n-1][n-1]);
    return mn;
}