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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int rdx0[4] = {-1, 1, -1, 1};
int rdy0[4] = {1, 1, 0, 0};
int rnx0[4] = {-1, 0, -1, 0};
int rny0[4] = {0, 0, 1, 1};

int rdx1[4] = {1, 1, 0, 0};
int rdy1[4] = {-1, 1, 1, -1};
int rnx1[4] = {0, 0, 1, 1};
int rny1[4] = {-1, 0, 0, -1};

int x, y, d, N;
int brd[105][105];
int dist[105][105][2];

void setArr(const vector<vector<int>>& board) {
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            brd[i][j] = board[i-1][j-1];
    }
    
    for (int i=0; i<105; i++) {
        for (int j=0; j<105; j++) {
            for (int k=0; k<2; k++)
                dist[i][j][k] = -1;
        }
    }
}

bool check(int a, int b, int dir) {
    
    if (a == N && b == N) return true;
    if (a+dx[dir] == N && b+dy[dir] == N) return true;
    return false;
}

bool OOB(int a, int b) {
    return a <= 0 || a > N || b <= 0 || b > N;
}

int bfs(const vector<vector<int>>& board) {
    
    queue<iii> q;
    q.push({1, 1, 0});
    dist[1][1][0] = 0;

    while (!q.empty()) {
        
        tie(x, y, d) = q.front();
        if (check(x, y, d)) return dist[x][y][d];
        q.pop();
        
        //상하좌우 이동
        for (int i=0; i<4; i++) {
            int nx1 = x+dx[i];
            int ny1 = y+dy[i];
            int nx2 = x+dx[d]+dx[i];
            int ny2 = y+dy[d]+dy[i];
            if (OOB(nx1, ny1) || OOB(nx2, ny2)) continue;
            if (brd[nx1][ny1] || brd[nx2][ny2]) continue;
            if (dist[nx1][ny1][d] != -1) continue;
            q.push({nx1, ny1, d});
            dist[nx1][ny1][d] = dist[x][y][d]+1;
        }
        
        //회전
        if (d == 0) {
            for (int i=0; i<4; i++) {
                int chx = x+rdx0[i];
                int chy = y+rdy0[i];
                int nx1 = x+rnx0[i];
                int ny1 = y+rny0[i];
                int nx2 = nx1+dx[1];
                int ny2 = ny1+dy[1];
                if (OOB(chx, chy) || OOB(nx1, ny1) || OOB(nx2, ny2)) continue;
                if (brd[chx][chy] || brd[nx1][ny1] || brd[nx2][ny2]) continue;
                if (dist[nx1][ny1][1] != -1) continue;
                q.push({nx1, ny1, 1});
                dist[nx1][ny1][1] = dist[x][y][d]+1;
            }
        }
        else {
            for (int i=0; i<4; i++) {
                int chx = x+rdx1[i];
                int chy = y+rdy1[i];
                int nx1 = x+rnx1[i];
                int ny1 = y+rny1[i];
                int nx2 = nx1+dx[0];
                int ny2 = ny1+dy[0];
                if (OOB(chx, chy) || OOB(nx1, ny1) || OOB(nx2, ny2)) continue;
                if (brd[chx][chy] || brd[nx1][ny1] || brd[nx2][ny2]) continue;
                if (dist[nx1][ny1][0] != -1) continue;
                q.push({nx1, ny1, 0});
                dist[nx1][ny1][0] = dist[x][y][d]+1;
            }
        }
        
    }
    
    return -1;
}

int solution(vector<vector<int>> board) {
    
    N = (int)board.size();
    setArr(board);
    return bfs(board);
}